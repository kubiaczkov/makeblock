// // Wywołuje "syrenę" po kombinacjii przycisków A i B

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeIR ir;
MeRGBLed rgbled_7(7, 2);
MeBuzzer buzzer;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while (millis() < endTime) _loop();
}

void setup() {
  ir.begin();
  bool x = false;
  int last = 0;
  rgbled_7.fillPixelsBak(0, 2, 1);
  while (!x) {
    if (ir.keyPressed(69)) {
      last++;
    }

    if (ir.keyPressed(70) && last>0) {
      x = true;
    }
    _loop();
  }


  for (int count = 0; count < 5; count++) {

    rgbled_7.setColor(0, 0, 0, 0);
    rgbled_7.show();

    rgbled_7.setColor(2, 0, 0, 60);
    rgbled_7.show();

    buzzer.tone(950, 0.6 * 1000);

    rgbled_7.setColor(0, 0, 0, 0);
    rgbled_7.show();

    rgbled_7.setColor(1, 0, 0, 60);
    rgbled_7.show();

    buzzer.tone(700, 0.4 * 1000);
  }
}

void _loop() {
  ir.loop();
}

void loop() {
  _loop();
}
