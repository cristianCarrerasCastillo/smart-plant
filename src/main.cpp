#include <Arduino.h>

const int sensor_humedad = A0;
int motor = 9; //conectado a pin digital 9
int read_humedad = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  read_humedad = analogRead(sensor_humedad);  
  read_humedad = map(read_humedad, 0, 1023, 0, 100);
  Serial.print("Humedad en: ");
  Serial.println(read_humedad);
  // Con una lectura de 22 es cuando la tierra esta recien regada
  // sobre 50 la tierra esta seca

  if (read_humedad > 50){
    Serial.println("Se enciende el motor");
    analogWrite(motor, 255);
    //por X seg, la función delay esta en ms
    delay(2000); // dos segundos
    Serial.println("Se apaga el motor");
    analogWrite(motor, 0);
  }
  delay(5000);
}
