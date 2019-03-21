WARNINGS := -Wall -Wextra -Werror
COMPILER := i686-elf-g++

CPPSRC := kernel.cpp vgatext.cpp
CPPFLAGS := -std=c++11 -ffreestanding -mno-red-zone -fno-exceptions -nostdlib -fno-rtti
LINKER := link.ld
EXEC := os

all:
	nasm boot.asm -f elf32 -o boot.o
	nasm io.asm -f elf32 -o io.o
	$(COMPILER) $(CPPSRC) io.o boot.o $(CPPFLAGS) -o $(EXEC) -T $(LINKER)
run:
	qemu-system-i386 $(EXEC)
	
hex:
	hexdump -Cv $(EXEC)
	
