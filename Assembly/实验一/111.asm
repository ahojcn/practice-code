; multi-segment executable file template.

data segment
    dat1 dw 12
ends

code segment
	assume cs:code, ds:data
	
start:
    mov ax, data
    mov ds, ax
	
    mov bx, dat1
    mov cx, 16

	T:  
	shl bx, 1 ;逻辑左移
	jc  prf
	mov dl,30h
	jmp shw
	prf:
		mov dl,31h
	shw:
		mov ah,2
	int 21h
	loop T
	
	; return dos
	mov ah, 4ch
	int 21h
	
ends
end start ; set entry point and stop the assembler.
