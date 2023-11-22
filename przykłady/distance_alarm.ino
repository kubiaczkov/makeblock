// program wywołuje Buzzer
// kiedy odległość od mBota jest poniżej 5 cm

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeUltrasonicSensor ultrasonic_3(3);
MeBuzzer buzzer;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  while(1) {
      if(ultrasonic_3.distanceCm() < 5){

        buzzer.tone(440, 0.25 * 1000);
        _delay(0.02);

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}

