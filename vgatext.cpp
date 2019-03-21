#include "vgatext.h"

namespace VGA {
	uint16_t line = 0;
	uint16_t column = 0;
	
	void putchar(char c, Color color) {
		if (c == '\n') {
			column = 0;
			line++;
		} else {
			TEXT_LOC[line * COLUMN_COUNT + column++] = color << 8 | c;
		}
	}
	
	void print(const char* text, Color color) {
		while (*text != 0) {
			putchar(*text, color);
			text++;
		}
	}
	
	void print(uint32_t number, Color c) {
		char buffer[PRINT_BUFFER_SIZE];
		uint8_t len = 0;
		
		if (number == 0) {
			buffer[len++] = '0';
		} else {
			while (number > 0) {
				buffer[len++] = number % 10 + '0';
				number /= 10;
			}
		}
		
		for (signed char i = len - 1; i >= 0; i--) { // TODO fix this
			putchar(buffer[i]);
		}
	}
	
	/*void print(sint32_t number, Color c) {
		
	}*/
	
	void println(const char* text, Color color) {
		print(text, color);
		if (line == LINE_COUNT) {
			line = 0;
		} else {
			line++;
		}
		column = 0;
	}
}
