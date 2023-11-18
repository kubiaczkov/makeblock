Wygeneruj pdf za pomocą https://www.markdowntopdf.com/

Będzie trzeba prawdopodobnie zuploadować ss żeby wygenerować pdfa

# Podręcznik użytkownika dla **mBot** przy użycia języku **Arduino**


Informacje zawarte w tym podręczniku mogą zawierać błędy, dziękuję za wyrozumiałość.

IDE wykorzystywane do **programowania urządzenia online** mBot v1.1. dostępne pod linkiem: https://ide.mblock.cc/

Kiedy chcemy używać jedynie kodu Arduino o wiele wygodniej będzie nam pracować w **Arduino IDE**, instrukcja konfiguracji oprogramowania znajduje się w folderze dosc.

## Instalacja wymaganego oprogramowania

Jeżeli chcemy wgrywać programy do naszego mBota przy pomocy połączenia kablowego USB A->B, musimy uprzednio zainstalować odpowiednie oprogramowanie.

>Instalator oprogramowania _mLink_ dostępny jest pod linkiem: https://www.mblock.cc/en/download/mlink/

![](./ss/Screenshot_1.png)

Wybieramy oprogramowanie odpowiednie dla naszego systemu. 

<span style="color:red; font-weight: 700;"> Poniższe czynności na podłączonym oraz uruchomionym urządzeniu! </span>

Przechodząc poprzez proces instalacji, poza samym oprogramowaniem mLink instalujemy również odpowiednie sterowniki.

![](./ss/Screenshot_3.png)

## Połączenie z urządzeniem w IDE

Aby móc importować nasze programy do urządzenia mBot, musimy je połączyć wewnątrz oprogramowania do kodowania. Robimy to wybierając u dołu okranu przycisk "połączenie"

![](./ss/Screenshot_2.png)

Zatwierdzamy konfigurację połączenia na porcie **COM3** przy pomocy **USB**. W tym momencie nasze urządzenia powinny być ze sobą połączone.

# Programowanie

IDE mBlock umożliwia tworzenie programów na dwa sposoby

- programowanie blokowe - _Scratch_
- programowanie obiektowe - _Arduino_

Tworząc program blokowy mamy możliwość podglądu kodu Arduino, jednak nie możemy go z tego poziomu edytować. W tym podręczniku skupimy się na programowaniu z użyciem języka programowania _Arduino_.

### Uruchomienie programu

Aby uruchomić napisany program, trzeba aktywować odpowiednią zakładkę "Arduinoc".

[<img src="./ss/Screenshot_4.png" width="380"/>](./ss/Screenshot_4.png)

Naszym oczom ukaże się edytor tekstowy z otwartym plikiem **mcore.ino**

<span style="color:red; font-weight: 700;"> UWAGA: nie zmieniamy jego nazwy ani rozszerzenia! </span>

## HELLO WORLD

Każy napisany przez nas program, będzie zaczynał się od identycznej składni, a konkretnie

```cpp
#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
}

void _loop() {
}

void loop() {
  _loop();
}
```

Ten schemat posiada cztery zaimplemetowane funkcje:

- _delay - służącą do tworzenia opóźnienia w działaniu programu, przyjmuje parametr _float seconds_, czyli podajemy w postaci zmiennoprzecinkowej ile sekund ma trwać przerwa **np.: _delay(0.5)** zatrzyma nam program na pół sekundy.
- setup - będziemy umieszczać tutaj instrukcję, które chcemy aby **wykonały się na starcie**
- loop - będziemy umieszczać tutaj instrukcję, które chcemy aby **się powtarzały w nieskończoność**

> TIP: możemy również zamiast funkcji _loop_ wykorzystać nieskończoną pętle while wewnątrz funkcji _setup_ co będziemy robić najczęściej

Przykład:

```cpp
void setup() {
  while(true) {
    // code here
    _loop();
  }
}
```

> ZAPAMIĘTAJ: nie zapomnij o wszystkich **#include** :)
***

### Uruchomienie programu

Aby uruchomić program musimy przesłać nasz kod do robota. Robimy to za pomocą przycisku "Załaduj z pliku" 

[<img src="./ss/Screenshot_5.png" width="220"/>](./ss/Screenshot_5.png)

> TIP: w przypadku problemów w załadowaniem programu pomaga ponowne przesłanie lub  ponowne uruchomienie robota. Jeżeli to nie pomaga potrzebny będzie **hard reset** przy pomocy odpowiedniego przycisku na płycie głównej 

### ZANIM PRZEJDZIEMY DO PROGRAMOWANIA

Programowanie urządzeń typu robot wymaga jeszcze dodatkowej porcji wiedzy, o co konkretnie chodzi? W najprostrzych programach komputerowych **operacje wejścia/wyjścia** zazwyczaj wykonujemy z poziomu _konsoli_, w tym przypadku musimy korzystać z faktycznych urządzeń **we/wy** takich jak:

- **czujniki** np. linii, światła
- **diody LED**
- **ekran LED**
- **silniki sterujące**
- itp.

Także, zanim będziemy w stanie wykonać pierwsze czynności musimy zapoznać się z _obsługą_ takich urządzeń.

> Każde urządzenie będzie wymagało wykorzystania odpowiednich **obiektów** w programie. Niestety dokumentacja jest mocno okrojona, w zasadzie to jej nie ma.


## Przegląd urządzeń

Od razu na wstępie zaznaczę, że nie wszystko w tym poradniku będzie wytłumaczone od deski do deski, bardziej skupimy się na przykładach użycia. Także, do dzieła!

### No. 1 - DIODY LED
***

W naszym urządzeniu diody LED występują w parze i pozwalają wyświetlać dowolny kolor w **gammie barw RGB**.

Aby użyć w naszym programie diod musimy na początku programu dodać obiekt klasy _MeRBGLed_.

```cpp
MeRGBLed rgbled_7(7, 2);
```

Następnie wewnątrz funkcji setup musimy dopisać

```cpp
rgbled_7.fillPixelsBak(0, 2, 1);
```

Po takiej konfiguracji w dalszej części programu w prosty sposób będziemy mogli wykorzystać diody LED. Dwie podstawowe funkcje:

```cpp 
rgbled_7.setColor(0, 255, 0, 0);
rgbled_7.show();
```
Powyższy kod wyświetli nam kolor **czerwony** na oby diodach. Metoda _setColor_ ma następującą składnie _setColor(opt, R, G, B)_.

Wartości _opt_ mogą być następujące:

- **0** - obie diody
- **1** - prawa dioda
- **2** - lewa dioda

Metoda _show_ odpowieda za wyświetlenie ustalonego koloru.

>TIP: aby zmiany kolorów były płynne powinniśmy wkorzystać funkcję _delay_

### No. 2 - BUZZER
***

Robot **mBot** posiada również buzzer pozwalający odtwarzać dźwięki! Aby móc być usłyszanym, również potrzebujemy użyć odpowiedniego obiektu.

```cpp
MeBuzzer buzzer;
```

W tym przypadku użycie jest jeszcze prostrze! Wystarczy nam opanować jedną funkcję _tone_.

```cpp 
buzzer.tone(950, 0.6 * 1000);
```
Metoda _tone_ ma następującą skladnie _tone(Hz, duration)_. Czyli powyższy kod przez 0.6 sekundy będzie nam odgrywać dźwięk o częstotliwości 950Hz.

- **Hz** - wartość z zakresu 20 do 20000
- **duration** - czas trania w ms, _równanie X * 1000_ da nam X sekund trwania dźwięku

> TIP: tak samo możemy wywoływanie dźwięków mieszać z przerwami _delay_


### No. 3 - EKRAN LED
***

W naszym wyposażeniu znajduje się coś co pozwoli nam w czytelny sposób przedstawić różnego rodzaju informację. Jest to ekran LED. 

Ekran jest zbudowany ze **105** diod (15x7), co pozwala nam wyświetlać za jego pomocą liczby, **maksymalnie 4 cyfrowe**, teksty (o ile się zmieszczą), czas w formacie **HH:MM** oraz różnego rodzaju **bitmapy**.

Aby rozpocząć pracę z ekranem LED musimy jak zawsze stworzyć odpowiedni obiekt. Parametr przekazywany do konstruktora to **numer portu** do którego podłączony jest ekran.

```cpp
MeLEDMatrix ledMtx_1(1);
```

#### Przypadki użycia

Zacznijmy od tego, że ekran może działać w dwóch konfiguracjach świetlnych. Wyświetlana zawartość jest rysowana lub jest obrysowywana. Parametr metody _setColorIndex_ przyjmuje wartości **true** (rysowanie - domyślne) lub **false** (obrysowywanie).

```cpp
void MeLEDMatrix::setColorIndex(bool Color_Number)
```

Z samych konfiguracji świetlnych, jesteśmy w stanie również zmienić jasność. Zakres jaśności jest od **0 do 8**, gdzie 0 to brak jaśności, a 8 to najjaśniejsza konfiguracja.

```cpp
void MeLEDMatrix::setBrightness(uint8_t Bright)
```

Dostępną przestrzeń roboczą możemy kreatywnie wykorzystywać do wyświetlania krotkich komunikatów. Pozwoli nam na to metoda _drawStr_, do wywołania której potrzebujemy 3 parametry. Pierwsze dwa odpowiedają za **pozycję startową** pisania, jest to wyzanczenie dolnego lewego rogu.

>TIP: można wartość _X_Position_ ustawić na wartość -1 aby wykorzystać całą dostępna przestrzeń rysowania

Przeci parametr wywołania to najprościej mówiąc nasz tekst, będziemy go generować w specjalny sposób. Dokumentacja przedstawia strukturę metody w taki sposób _void MeLEDMatrix::drawStr(int16_t X_position, int8_t Y_position, const char *str)_. Poniżej przykład użycia:

```cpp
ledMtx_1.drawStr(0, 7, String("XYZ").c_str());
```

Kolejną bradzo przydatną możliwościa jest wyświetlanie czasu. Konkretnie w **formacie HH:MM**. Oczywiście łatwo zauważyć, że przy odpowiedniej kombinacji nie będzie problemu z przerobieniem wyświetlanego formatu na **MM:SS**. Schemat metody według dokumentacji _void MeLEDMatrix::showClock(uint8_t hour, uint8_t minute, bool point_flag)_. Poniżej przykład użycia:

```cpp
ledMtx_1.showClock(2, 30);
```

Dla ułatwienia wyświetlania wartości liczbowych mamy specjalnie przeznaczoną do tego metodę _showNum_. Wymaga ona jednego parametru, którym jest rzeczona wartość - może ona przyjmować **typ int lub float**. Musimy jednak pamiętać, że kropka zajmie nam jedną pozycję na ekranie. Przykład użycia:

```cpp
ledMtx_1.showNum(1234);
_delay(1);
ledMtx_1.showNum(10.1); // 4 znaki wraz z kropką
```

Ostanią metodą z pakiety Ekran LED - jest nic bardziej prostrzego, a konkretnie to czyszczenie tego ekranu. Metoda _clearScreen_ czyści nam ekran.

```cpp
ledMtx_1.clearScreen()
```