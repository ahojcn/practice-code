; multi-segment executable file template.

data segment
    ; add your data here!
    dat1 dw 12
ends

;stack segment
;    dw   128  dup(0)
;ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
	
    mov bx, dat1
    mov cx, 16

    ; add your code here
T:  shl bx, 1 ;逻辑左移
	jc  prf
	mov dl,30h
	jmp shw
prf:mov dl,31h
shw:mov ah,2
	int 21h
	loop T
	
ends

end start ; set entry point and stop the assembler.
