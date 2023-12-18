/*
Dev: Cristian Carreras
date: 16/11/23
*/

#include <Arduino.h>
#include <RTClib.h> 

const int sensor_humedad = A0;
int motor = 9; //Tip 120 conectado a pin digital 9
int read_humedad = 0;

RTC_DS1307 rtc;
bool hora_de_regar = false;

void setup() {
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.print("la hora se actualizará a la siguiente: ");
    Serial.print(F(__DATE__));
    Serial.print(" - ");
    Serial.println(F(__TIME__));

  }
  delay(500);
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //cada vez que se compile, se le actualizará la hora
  Serial.println("setup terminado");
}

int leerHumedad(){
  read_humedad = analogRead(sensor_humedad);  
  read_humedad = map(read_humedad, 0, 1023, 0, 100);
  return(read_humedad);
}

void loop() {
  DateTime now = rtc.now();

  read_humedad = leerHumedad();
  Serial.print("Humedad en: ");
  Serial.println(read_humedad);
  
  if(now.hour() == 6 or now.hour() == 23){
    hora_de_regar = true;
  }

  if(hora_de_regar == true){

    if(read_humedad > 400 ){
      Serial.println("Se enciende el motor");
      //analogWrite(motor, 255);
      delay(3000);//riega 3 seg antes de hacer otra comparación
    }
    else{
      Serial.println("Se apaga el motor");
      //analogWrite(motor, 0);
      hora_de_regar = false;
    }
  }

  delay(10000);
}