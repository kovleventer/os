bits 32

global read_byte
read_byte:
	mov dx, ax
	in al, dx
	ret
