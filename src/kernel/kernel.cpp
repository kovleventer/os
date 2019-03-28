#include "graphics/vgatext.h"
#include "io.hpp"
#include "input/keyboard.h"

extern "C"
void kmain() {
	VGA::println("it works", VGA::LIGHT_MAGENTA);
	VGA::println("text\nmode", VGA::GREEN);
	VGA::print(134);
	VGA::println();
    while (1) {
		uint8_t input = IO::read_byte(0x64);
		//VGA::print(input);
		//VGA::println();
		if (input & 1) {
			uint8_t iodev = IO::read_byte(0x60);
			if (iodev < 128) {
				VGA::putchar(Keyboard::layout[iodev]);
			}
		}
		//Utils::sleep();
	}
}
