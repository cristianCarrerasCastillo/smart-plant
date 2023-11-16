/*
Dev: Cristian Carreras
date: 16/11/23
*/

#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <util/atomic.h>

/* Nota del desarrollador
3600s = 1 hr 
el tiempo maximo que se puede setear en un timer de 16bits
es de aprox 4194 segundos, lo que es equivalente a 1:10 hrs
Tener consideración de esto, si se setea en más tiempo, se
tendra un error de desbordamiento de memoria y el programa
va a crashear.
*/
const int sleepTimeSeconds = 3600; 

const int sensor_humedad = A0;
int motor = 9; //conectado a pin digital 9
int read_humedad = 0;

void setup() {
  Serial.begin(9600);
}

void enterSleep() {
  // Configurar el modo de bajo consumo
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  // Configurar el temporizador (Timer/Counter1) para generar una interrupción después del tiempo deseado
  cli();
  TCCR1A = 0; // Configurar Timer/Counter1 en modo normal
  TCCR1B = (1 << CS12) | (1 << CS10); // Configurar preescalador para 1024
  TCNT1 = 0; // Reiniciar el contador
  TIMSK1 |= (1 << TOIE1); // Habilitar la interrupción de desbordamiento del temporizador
  sei();

  // Entrar en el modo de bajo consumo
  sleep_mode();
}

// Rutina de interrupción para el temporizador
ISR(TIMER1_OVF_vect) {
  // Incrementar el contador de segundos
  static int seconds = 0;
  seconds++;

  // Despertar después de que haya pasado el tiempo deseado
  if (seconds >= sleepTimeSeconds) {
    sleep_disable();
    power_all_enable();
    seconds = 0; // Reiniciar el contador
  }
}

void loop() {
  read_humedad = analogRead(sensor_humedad);  
  read_humedad = map(read_humedad, 0, 1023, 0, 100);
  Serial.print("Humedad en: ");
  Serial.println(read_humedad);
  /* Nota del desarrollador 
  - Con una lectura de 22 es cuando la tierra esta recien regada
  - Sobre 50 la tierra esta seca
  Aqui habria que aplicar una logica de 100 - read_humedad
  que francamente no quise implementar por "flojera", porque
  es algo tan minimo, pero creo que me demore más en escribir
  esto que en "corregir" la logica
  */

  if (read_humedad > 50){
    Serial.println("Se enciende el motor");
    analogWrite(motor, 255);
    //por 2 seg, la función delay esta en ms
    delay(2000); // dos segundos
    Serial.println("Se apaga el motor");
    analogWrite(motor, 0);
  }
  Serial.println("Al tuto por 1hr");
  enterSleep();
}
