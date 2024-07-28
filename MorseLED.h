/*
  MorseLED.h
  Created by Jevgeny Skorik, 28.07.2024.
*/

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class MorseLED {
    public:
        MorseLED(int pin, int delay = 400);
        void init();
        void display_str(char* str);
    private:
        int pin_;
        int delay_;
        const char* char_to_morse_str(char c);
        void str_to_morse_str(char* str, char* morse_str);
        void display_char(char c);
};

#endif