#pragma once

#include <stdint.h>

namespace VGA {
	
	const uint8_t LINE_COUNT = 24;
	const uint8_t COLUMN_COUNT = 80;
	
	uint16_t* const TEXT_LOC = (uint16_t*)0xB8000;
	
	const uint16_t PRINT_BUFFER_SIZE = 16;
	
	enum Color {
		BLACK = 0,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHT_GRAY,
		DARK_GRAY,
		LIGHT_BLUE,
		LIGHT_GREEN,
		LIGHT_CYAN,
		LIGHT_RED,
		LIGHT_MAGENTA,
		YELLOW,
		WHITE
	};
	
	void putchar(char c, Color color = WHITE);
	
	void print(const char* text, Color c = WHITE);
	
	void print(uint32_t number, Color c = WHITE);
	//void print(sint32_t number, Color c = WHITE);
	
	void println(const char* text, Color c = WHITE);
}
