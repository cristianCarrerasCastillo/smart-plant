/*
Dev: Cristian Carreras
date: 16/11/23
*/

#include <Arduino.h>

const int sensor_humedad = A0;
int motor = 9; //Tip 120 conectado a pin digital 9
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

  if(read_humedad > 29){
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
