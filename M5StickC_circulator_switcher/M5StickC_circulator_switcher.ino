/*
    note: need add library Adafruit_BMP280 from library manage
    Github: https://github.com/adafruit/Adafruit_BMP280_Library
*/

#include <M5StickC.h>
//#include "DHT12.h"
#include <WEMOS_DHT12.h>
#include <Wire.h>
#include "Adafruit_Sensor.h"
#include <ESP32Servo.h>

DHT12 dht12;

Servo servo1; // create four servo objects 
int32_t servo1_pin = 26;
const int32_t MIN_US = 500;
const int32_t MAX_US = 2400;

void setupServo(void)
{
  servo1.setPeriodHertz(50); // Standard 50hz servo
  servo1.attach(servo1_pin, MIN_US, MAX_US);
}

void setup() {
  // put your setup code here, to run once:
  M5.begin();

  Wire.begin(0,26);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  M5.Lcd.println("ENV TEST");
  pinMode(M5_BUTTON_HOME, INPUT);

  setupServo();
}

uint8_t setup_flag = 1;

void loop() {
  const int16_t ROTATE_ANGLE = 36;
  const int16_t INITIAL_ANGLE = 10;
  static int16_t pos = INITIAL_ANGLE;
  static int16_t inc = ROTATE_ANGLE;
  servo1.write(pos);
  pos += inc;
  if(pos >= ROTATE_ANGLE) inc = -ROTATE_ANGLE;
  else if(pos <= INITIAL_ANGLE)  inc = ROTATE_ANGLE;
  Serial.println(pos);

  M5.Lcd.setCursor(0, 20, 2);
  M5.Lcd.printf("Angle: %d ", pos);

  delay(10000);
#if 0
  float tmp = 0;
  if(dht12.get()==0){
    tmp = dht12.cTemp;
  }    
  // put your main code here, to run repeatedly:
  //float tmp = dht12.readTemperature();
  //float hum = dht12.readHumidity();
  M5.Lcd.setCursor(0, 20, 2);
  //M5.Lcd.printf("Temp: %2.1f Humi: %2.0f%%", tmp, hum);
  M5.Lcd.printf("Temp: %2.1f ", tmp);

 delay(2000);  
#endif
}
