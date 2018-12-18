code segment
	assume cs:code
	
start:
	mov bx,11 ;B
	sub ax,ax
	mov ch,4
rotate:
	mov cl,4
	rol bx,cl
	mov al,bl
	and al,0fH
	add al,30H
	cmp al,3aH
	jl  print
	add al,7H
print:
	mov dl,al
	mov ah,2
	int 21H
	dec ch
	jnz rotate
	mov dl,'H'
	mov ah,2
	int 21h
	
	; return dos
	mov ah, 4ch
	int 21h
	
code ends
end start


; multi-segment executable file template.

; data segment
    ; ; add your data here!
    ; dat1 dw 65535
; ends

; ;stack segment
; ;    dw   128  dup(0)
; ;ends

; code segment
; start:
; ; set segment registers:
; beg:mov ax, data
    ; mov ds, ax
    ; mov es, ax
    ; ; add your code here
	; mov bx, dat1
	; mov cx, 4
	; push cx
; t:	mov cl, 4
	; rol bx, cl
	; pop cx
	; mov dl, bl
	; and dl, 0fh
	; add dl, 30h
	; cmp dl, 39h
	; jbe prf
	; add dl, 7
; prf:mov ah, 2
	; int 21h
	; loop t
; ends

; end start ; set entry point and stop the assembler.
