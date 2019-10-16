#include "graphics/vgatext.h"
#include "io.hpp"
#include "input/keyboard.h"
#include "cpu/cpuid.h"

extern "C"
void kmain() {
	VGA::println("it works", VGA::LIGHT_MAGENTA);
	CPU::update_cpuid();
	VGA::println("text\nmode", VGA::GREEN);
	char vendor_id[13] = {0};
	VGA::println(CPU::get_vendor_id(vendor_id));
	VGA::print("Stepping id: ");
	VGA::print((uint32_t)CPU::get_steppingID());
	VGA::print("\nModel: ");
	VGA::print((uint32_t)CPU::get_model());
	VGA::print("\nFamily: ");
	VGA::print((uint32_t)CPU::get_family());
	VGA::print("\nVMX: ");
	VGA::print(CPU::ext_VMX());
	VGA::print("\nSSE3: ");
	VGA::print(CPU::ext_SSE3());
	VGA::print("\nRDRAND: ");
	//CPU::ext_RDRAND();
	VGA::print(CPU::ext_RDRAND());
	//VGA::print("A");
	VGA::println();
	
	
	/*VGA::print(rand());
	VGA::println();*/
	
	VGA::print(0 - 1, VGA::BIN);
	VGA::println();
    while (1) {
		uint8_t input64 = IO::read_byte(0x64);
		
		do {
			VGA::print(input64, VGA::BIN);
			VGA::println();
			for (uint8_t i = 0; i < 24; i++) VGA::println();
			/**uint32_t iodev =*/ IO::read_byte(0x60);
			//iodev++;
			/*int* a = (int*)0x7c00;
			*a = 0;*/
			
		} while (input64 & 0x01);
		//Utils::sleep();
		asm("cli");
		asm("hlt");
	}
}
