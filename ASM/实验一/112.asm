; multi-segment executable file template.

data segment
    ; add your data here!
    dat1 dw 12
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
	
    mov es, ax
    mov bx, dat1
    mov cx, 16

    ; add your code here
T:  rol bx,1 ;循环左移
	mov dl,bl
	and dl,01h
	add dl,30h
	mov ah,2
	int 21h
	loop T
	
ends

end start ; set entry point and stop the assembler.
