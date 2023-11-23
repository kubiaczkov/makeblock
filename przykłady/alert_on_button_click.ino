// Wywołuje "syrenę" podczas wciśnięcia przycisku

#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeRGBLed rgbled_7(7, 2);
MeBuzzer buzzer;

void _delay(float seconds)
{
    long endTime = millis() + seconds * 1000;
    while (millis() < endTime)
        _loop();
}

// Sprawdza czy przycisk został naciśnięty
bool _checkButton()
{
    if ((!(0 ^ (analogRead(A7) > 10 ? 0 : 1))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setup()
{
    pinMode(A7, INPUT);
    rgbled_7.fillPixelsBak(0, 2, 1);

    while (true)
    {
        while (_checkButton())
        {
            _loop();
        }

        for (int count = 0; count < 5; count++)
        {

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

        _loop();
    }
}

void _loop()
{
}

void loop()
{
    _loop();
}
