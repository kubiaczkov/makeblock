// program wywołuje Buzzer
// kiedy jasność jest powyżej 100

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLightSensor lightsensor_6(6);
MeBuzzer buzzer;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  lightsensor_6.lightOff();
  Serial.begin(9600);
      while(true) {
        if(lightsensor_6.read() > 100)
        {
          buzzer.tone(800, 1000);
          _delay(0.2);
        }
      }

      _loop();
  }



void _loop() {
}

void loop() {
  _loop();
}

