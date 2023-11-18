#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLEDMatrix ledMtx_1(1);

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while (millis() < endTime) _loop();
}

//! A LED screen can only contains 3 letter text
/*!
  \param a first letter.
  \param b second letter.
  \param c third letter.
  \return Three chars long input String.
*/
String getMessage(char a, char b, char c) {
  String output = "";
  String p1 = String(a);
  String p2 = String(b);
  String p3 = String(c);

  output = p1 + p2 + p3;
  return output;
}

void setup() {
  ledMtx_1.clearScreen();

  int strLen = 16;                        // ilość znaków w naszej wiadomości
  char str[strLen] = "  UDANEGO URLOPU";  // treść wiadomości z buforem na początku

  while (true) {
    ledMtx_1.setColorIndex(true);
    ledMtx_1.setBrightness(5);
    ledMtx_1.clearScreen();
    int i = 2;  // index pierwszej litery w naszej wiadomości
    _delay(2);

    while (true) {
      // wyświetlam jedynie 3 kolejne po sobie litery z wiadomości
      ledMtx_1.drawStr(-1, 7, getMessage(str[i - 2], str[i - 1], str[i]).c_str());
      // opóźniam efekt przesunięcia o 0.4 sekundy
      _delay(0.4);
      i++;
      if (i == strLen) {
        _delay(2);
        break;
      }
    }
    _loop();
  }
}

void _loop() {
}

void loop() {
  _loop();
}