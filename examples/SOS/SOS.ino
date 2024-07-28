#include <MorseLED.h>

MorseLED morse(13, 400);

void setup() {
  morse.init();
}

void loop() {
  morse.display_str("SOS");
}