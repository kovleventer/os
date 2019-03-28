#pragma once

namespace IO {
	inline uint8_t read_byte(uint16_t port) {
		uint8_t value;
		asm volatile (
			"inb %%dx, %%al;" : "=a" (value) : "d" (port)
		);
		return value;
	}
	
	inline uint16_t read_word(uint16_t port) {
		uint16_t value;
		asm volatile (
			"inw %%dx, %%ax;" : "=a" (value) : "d" (port)
		);
		return value;
	}
	
	inline uint32_t read_dword(uint16_t port) {
		uint32_t value;
		asm volatile (
			"inl %%dx, %%eal;" : "=a" (value) : "d" (port)
		);
		return value;
	}
	
	inline void write_byte(uint16_t port, uint8_t value) {
		asm volatile (
			"outb %%al, %%dx" :: "a" (value), "d" (port)
		);
	}
	
	inline void write_word(uint16_t port, uint16_t value) {
		asm volatile (
			"outb %%ax, %%dx" :: "a" (value), "d" (port)
		);
	}
	
	inline void write_dword(uint16_t port, uint32_t value) {
		asm volatile (
			"outb %%eax, %%dx" :: "a" (value), "d" (port)
		);
	}
}
