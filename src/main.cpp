/*
Dev: Cristian Carreras
date: 16/11/23
*/

#include <Arduino.h>
/*#include <avr/sleep.h>
#include <avr/power.h>
#include <util/atomic.h>
+/

/* Nota del desarrollador
3600s = 1 hr 
el tiempo maximo que se puede setear en un timer de 16bits
es de aprox 4194 segundos, lo que es equivalente a 1:10 hrs
Tener consideración de esto, si se setea en más tiempo, se
tendra un error de desbordamiento de memoria y el programa
va a crashear.
*/
//const int sleepTimeSeconds = 3600; 

const int sensor_humedad = A0;
int motor = 9; //conectado a pin digital 9
int read_humedad = 0;

void setup() {
  Serial.begin(9600);
}

int leerHumedad(){
  read_humedad = analogRead(sensor_humedad);  
  read_humedad = map(read_humedad, 0, 1023, 0, 100);
  return(read_humedad);
}

void loop() {
  read_humedad = leerHumedad();
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

  if(read_humedad > 50){
    read_humedad = leerHumedad();
    Serial.print("Humedad en: ");
    Serial.println(read_humedad);
    Serial.println("Se enciende el motor");
    analogWrite(motor, 255);
    delay(500);
  }
  else{
    Serial.println("Se apaga el motor");
    analogWrite(motor, 0);
    delay(3600);
  }
  
}
