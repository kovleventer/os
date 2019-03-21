bits 16
section .boot
global boot
boot:
	
	%include "a20.asm"
	
	mov ax, 0x03
	int 0x10
	cli
	
	mov ah, 0x02
	mov al, 6
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov bx, second_sector
	int 0x13
	
	; Loading gdt table
	lgdt [gdt]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	
	mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp CODE_SEG:second_sector
	
	gdt:
	; Horrible hack, using the null selector to store lgdt parameters
		dw GDT_SIZE
		dd gdt
		dw 0x0000
	gdt_code_seg:
		dw 0xFFFF
		dw 0x0000
		db 0x00
		db 10011010b
		db 11001111b
		db 0x00
	gdt_data_seg:
		dw 0xFFFF
		dw 0x0000
		db 0x00
		db 10010010b
		db 11001111b
		db 0x00
	gdt_end:
		
CODE_SEG equ gdt_code_seg - gdt
DATA_SEG equ gdt_data_seg - gdt
GDT_SIZE equ gdt_end - gdt

times 510-($-$$) db 0
dw 0xaa55 ; Signature
; End of first sector 

second_sector:
bits 32
	kernel_start:
		mov esp, kernel_stack_top
		extern kmain
		call kmain
	halt:
		hlt
		jmp halt
	
section .bss
align 4
kernel_stack_bottom: equ $
resb 16384
kernel_stack_top:

