#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


const int RX_PIN = 16;
const int TX_PIN = 17;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial2.begin(9600,SERIAL_8N1,RX_PIN,TX_PIN);//GPS
}

void loop() {
  while(Serial2.available()){
    SerialBT.write(char(Serial2.read()));
    Serial.print(char(Serial2.read()));
    
  }

}
