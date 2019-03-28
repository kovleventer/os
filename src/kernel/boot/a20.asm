; Enables tha a20 line
; TODO more complex checking and fallback solutions

A20_BIOS_DISABLE equ 0x2400
A20_BIOS_ENABLE equ 0x2401
A20_BIOS_STATUS equ 0x2402

mov ax, A20_BIOS_ENABLE
int 0x15
