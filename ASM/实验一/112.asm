; multi-segment executable file template.

data segment
    dat1 dw 12
ends

code segment
	assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax
	
    mov es, ax
    mov bx, dat1
    mov cx, 16

T:  rol bx,1 ;循环左移
	mov dl,bl
	and dl,01h
	add dl,30h
	mov ah,2
	int 21h
	loop T
	
	;return dos
	mov ah, 4ch
	int 21h
	
ends
end start
