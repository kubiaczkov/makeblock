// program wywołuje Buzzer
// kiedy mBot najeżdża na linię 


#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLineFollower linefollower_2(2);
MeBuzzer buzzer;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  while(1) {
      if(linefollower_2.readSensors() == 0.000000){

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

