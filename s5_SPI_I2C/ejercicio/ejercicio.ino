#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>

#include <Adafruit_BMP280.h>

#define LED 32
Adafruit_BMP280 bmp;
File readings;
char payload[50]; // datos a escribir en SD y serial

void setup() {
  Serial.begin(115200);
  bmp.begin(0x76);
  SD.begin();
  pinMode(LED, OUTPUT);
  readings = SD.open("/readings.csv",FILE_APPEND);
  readings.println("Temperatura,Presion");
  readings.close();
  Serial.println("Temperatura,Presion");
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level) 
  sprintf(payload,"%.2f,%.2f",bmp.readTemperature(),bmp.readPressure());
  Serial.println(payload);
  readings = SD.open("/readings.csv",FILE_APPEND);
  readings.println(payload);
  readings.close();
  //Serial.print(";");
  //Serial.println(bmp.readPressure());
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
