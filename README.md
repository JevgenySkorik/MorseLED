# MorseLED

An arduino library for transmitting text in morse code using an LED. This library turns a string of text into blinking instructions for your LED.

## Example:

MorseLED accepts two parameters:
1. *pin* number of your LED(13 in the example below) - **Required**;
2. *delay*, which determines how fast the LED is going to blink(400 in the example below) - **Optional** (uses 400 by default).

```c
#include <MorseLED.h>

MorseLED morse(13, 400);

void setup() {
  morse.init();
}

void loop() {
  morse.display_str("SOS");
}
```

## Installation
1. Download the repository as a .zip file.
2. Open Arduino IDE.
3. Navigate to Sketch -> Include Library -> Add .ZIP Library...
4. Select the downloaded .zip file and click Open.
5. To include the library, go to Sketch -> Include Library -> MorseLED-main.
