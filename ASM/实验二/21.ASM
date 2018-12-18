; 十进制输出，不输出前面的 0

;循环
;商不为0：输出商，push余数，continue，pop余数作为被除数
;商为0：pop余数，输出余数，结束循环

; 19/10  -> 1...9
; 9/10   -> 0...9

data segment
	data1 dw 13h
data ends

code segment
	assume cs:code, ds:data

start:
	mov ax, data
	mov ds, ax
	
	mov ax, data1
	call fun	; 调用10进制显示子程序
	;ret
	mov ax, 4ch	; return dos
	int 21h
	
	fun proc near
		mov cx, 0	; cx -> 0，计数器清 0
		mov bx, 10	; bx -> 10，除10
	q1:
		mov dx, 0	; dx 存余数，清0
		div bx		; dx:ax / bx ->(ax)商，(dx)余数
		xor dx, 30h	; dx ^ 110000
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
	fun endp

code ends
end start	
	