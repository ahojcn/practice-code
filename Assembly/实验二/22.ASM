; 输出带符号10进制数字

; 正数：直接输出
; 负数：取反+1，输出

data segment
	data1 dw 13h
data ends

code segment
	assume cs:code, ds:data

start:
	mov ax, data
	mov ds, ax
	
	mov ax, -13h;;;;;;;;;;;;;;;;
	;mov ax, data1
	call fun
	
	mov ah, 4ch	;return dos
    int 21h
	
	fun proc near
		and ax, ax
		jns prt10	;不是负数（正数），直接输出
		;负数：取反+1，输出
		mov dl, '-'	;输出'-'号
		mov ah, 2
		int 21h
		
		; 0110
		; 1111
		; 1001
		;xor bx, 0fh
		;inc bx	;inc 1
		mov ax, -13h;;;;;;;;;;;;;;;;
		;mov ax, data1
		neg ax
	
	prt10:
		;mov ax, bx
		call prtfun
		ret
	fun endp
	
	
	prtfun proc near
		;mov ax, bx
		;mov ax, 13h
		mov cx, 0	; cx -> 0，计数器清 0
		mov bx, 10	; bx -> 10，除10
	q1:
		mov dx, 0	; dx 存余数，清0
		div bx		; dx:ax / bx ->(ax)商，(dx)余数
		xor dx, 0030h	; dx ^ 110000
		push dx	; push dx，dx中存的余数，压栈
		inc cx	; cx++，计数器++
		cmp ax, 0
		jnz q1 	; 如果ax（商）不为 0 就继续上面除10操作
	q2:
		pop dx
		mov ah, 2
		int 21h
		loop q2
		ret
	prtfun endp