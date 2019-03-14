; 在数据段定义一个数组，其中存放若干个dw类型数据
; 编写程序将数组中元素以十进制形式显示。
data segment
	arr dw 0,1,2,3,4,5,6,7,8,9
	n dw 10	;数组元素数量
data ends
	
code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	
	mov cx, n
	lea si, arr
	T:
	mov ax, [si]
	push cx	;;;;;;;;;;;
	call fun
	call space
	add si, 2	; dw
	pop cx	;;;;;;;;;;;
	loop t
	
	; return dos
	mov ah, 4ch
	int 21h
	
	;空格
	space proc near
		mov dl, 20h
		mov ah, 2
		int 21h
		ret
	space endp
	
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