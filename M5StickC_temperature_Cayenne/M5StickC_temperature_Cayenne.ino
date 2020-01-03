#include <M5StickC.h>
#include "DHT12.h"
#include <Wire.h>

DHT12 dht12; 

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  Wire.begin(0,26);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  M5.Lcd.println("ENV DHT12");
}

void loop() {
  // put your main code here, to run repeatedly:
  float tmp = dht12.readTemperature();
  float hum = dht12.readHumidity();
  M5.Lcd.setCursor(0, 20, 2);
  M5.Lcd.printf("Temp: %2.1f Humi: %2.0f%%", tmp, hum);

 delay(2000);

}
