#include "vgatext.h"
#include "io.h"

extern "C"
void kmain() {
	VGA::println("it works", VGA::LIGHT_MAGENTA);
	VGA::println("text\nmode", VGA::GREEN);
	VGA::print(134);
}
