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
	
	void print(uint32_t number, uint8_t base, Color c) {
		char buffer[PRINT_BUFFER_SIZE];
		uint8_t len = 0;
		
		if (number == 0) {
			buffer[len++] = '0';
		} else {
			while (number > 0) {
				uint32_t mod = number % base;
				buffer[len++] = mod >= DEC ? 'A' + mod - DEC : '0' + mod;
				number /= base;
			}
		}
		
		if (base == HEX) {
			putchar('0');
			putchar('x');
		} else if (base == BIN) {
			putchar('b');
			while (len < 8) {
				buffer[len++] = '0';
			}
		}
		
		for (int8_t i = len - 1; i >= 0; i--) {
			putchar(buffer[i], c);
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
