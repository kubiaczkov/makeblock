// miganie obu diod na kolor czerwony

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeRGBLed rgbled_7(7, 2);

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  rgbled_7.fillPixelsBak(0, 2, 1);
  for(int count=0;count<10;count++){

    rgbled_7.setColor(0, 60, 0, 0);
    rgbled_7.show();
    _delay(1);

    rgbled_7.setColor(0, 0, 0, 0);
    rgbled_7.show();
    _delay(1);
  }

}

void _loop() {
}

void loop() {
  _loop();
}

