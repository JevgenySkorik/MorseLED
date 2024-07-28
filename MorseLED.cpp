/*
  MorseLED.h
  Created by Jevgeny Skorik, 28.07.2024.
*/

#include "Arduino.h"
#include "MorseLED.h"
#include "string.h"
#include <stdlib.h>

MorseLED::MorseLED(int pin, int delay) : 
	pin_{pin}, delay_{delay} {
}

void MorseLED::init() {
	pinMode(pin_, OUTPUT);
}

const char* MorseLED::char_to_morse_str(char c) {
	switch (c) {
		case 'A':
			return ".- ";
		case 'B':
			return "-... ";
		case 'C':
			return "-.-. ";
		case 'D':
			return "-.. ";
		case 'E':
			return ". ";
		case 'F':
			return "..-. ";
		case 'G':
			return "--. ";
		case 'H':
			return ".... ";
		case 'I':
			return ".. ";
		case 'J':
			return ".--- ";
		case 'K':
			return "-.- ";
		case 'L':
			return ".-.. ";
		case 'M':
			return "-- ";
		case 'N':
			return "-. ";
		case 'O':
			return "--- ";
		case 'P':
			return ".--. ";
		case 'Q':
			return "--.- ";
		case 'R':
			return ".-. ";
		case 'S':
			return "... ";
		case 'T':
			return "- ";
		case 'U':
			return "..- ";
		case 'V':
			return "...- ";
		case 'W':
			return ".-- ";
		case 'X':
			return "...- ";
		case 'Y':
			return "-.-- ";
		case 'Z':
			return "--.. ";
		case '1':
			return ".---- ";
		case '2':
			return "..--- ";
		case '3':
			return "...-- ";
		case '4':
			return "....- ";
		case '5':
			return "..... ";
		case '6':
			return "-.... ";
		case '7':
			return "--... ";
		case '8':
			return "---.. ";
		case '9':
			return "----. ";
		case '0':
			return "----- ";
		case ' ':
			return "/ ";
	}
}

void MorseLED::str_to_morse_str(char* str, char* morse_str) {
	for (size_t i = 0; i < strlen(str); i++) {
		strcat(morse_str, char_to_morse_str(str[i]));
	}
}

void MorseLED::display_char(char c) {
	if (c == '-') {
		digitalWrite(pin_, HIGH);
		delay(delay_ * 3);
	} else if (c == '.') {
		digitalWrite(pin_, HIGH);
		delay(delay_);
	} else if (c == ' ') {
		delay(delay_ * 2);
	} else if (c == '/') {
		delay(delay_ * 3);
	}

	digitalWrite(pin_, LOW);
	delay(delay_);
}

void MorseLED::display_str(char* str) {
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);

	char* morse_str = (char*)malloc(strlen(str)+1);
	str_to_morse_str(str, morse_str);
	for (size_t i = 0; i < strlen(morse_str); i++) {
		display_char(morse_str[i]);
	}
	free(morse_str);

	delay(delay_ * 7);
}