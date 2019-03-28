WARNINGS := -Wall -Wextra -Werror
CPP_COMPILER := i686-elf-g++
ASSEMBLER := nasm
PROJDIRS := src

CPPSRC := $(shell find $(PROJDIRS) -type f -name \*.cpp)
ASMSRC := $(shell find $(PROJDIRS) -type f -name \*.asm)

OBJFILES := $(patsubst %.cpp, %.o, $(CPPSRC)) $(patsubst %.asm, %.asm_o, $(ASMSRC))

CPPFLAGS := -std=c++11 -O2 -ffreestanding -mno-red-zone -fno-exceptions -fno-rtti
LINKERFLAGS := -nostdlib
ASMFLAGS := -f elf32
LINKER := src/link.ld
EXEC := os

.PHONY: all, run

%.o: %.cpp
	$(CPP_COMPILER) $< $(WARNINGS) $(CPPFLAGS) -c -o $@
	
%.asm_o: %.asm
	$(ASSEMBLER) $< $(ASMFLAGS) -o $@

all: $(OBJFILES)
	$(CPP_COMPILER) $(OBJFILES) $(LINKERFLAGS) -o $(EXEC) -T $(LINKER)
	
clean:
	-@rm $(OBJFILES) $(EXEC)
	
# Misc
run:
	qemu-system-i386 $(EXEC)
	
hex:
	hexdump -Cv $(EXEC)
	
