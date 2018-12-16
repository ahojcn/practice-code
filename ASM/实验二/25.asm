; 求数组中负数个数程序
; 要求：在数据段定义一个数组
; 其中存放若干个dw类型带符号数据
; 编写程序求数组中负数个数
; 并将数组元素及负数个数输出。

data segment
	arr dw -1,1,-2,3,-4,5,-6,7,-8,9
	n dw 10
	msg db 'number of negative:', '$'
data ends

code segment
	assume cs:code, ds:data

start:
	mov ax, data
	mov ds, ax
	
	; 输出数组元素
	call printArr
	
	; count 负数
	call count
	
	
	
	
	; return dos
	mov ah, 4ch
	int 21h
	
	count proc near
		mov cx, n
		lea si, arr
		mov dx, 0	; 计数器清0
		t:
		mov ax, [si]
		push cx	;;;;;;;;;;;
		
		;;;
		and ax, ax
		jns nextNum	;不是负数（正数）
		inc dx
		;;;
	nextNum:
		add si, 2	; dw
		pop cx	;;;;;;;;;;;
		loop t
		
		push dx
		call newline
		
		mov dx, offset msg
		mov ah, 09h
		int 21h
		
		pop ax
		call prtfun
		ret
	count endp
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	;回车换行
	newline proc near
		mov dl,0ah
		mov ah,02h
		int 21h
		mov dl,0dh
		mov ah,02h
		int 21h
		ret
	newline endp
	
	;空格
	space proc near
		mov dl, 20h
		mov ah, 2
		int 21h
		ret
	space endp
	
	printArr proc near
		mov cx, n
		lea si, arr
		tt:
		mov ax, [si]
		push cx	;;;;;;;;;;;
		call fun
		call space
		add si, 2	; dw
		pop cx	;;;;;;;;;;;
		loop tt
		ret
	printArr endp
	
	fun proc near
		and ax, ax
		push ax
		jns prt10	;不是负数（正数），直接输出
		;负数：取反+1，输出
		mov dl, '-'	;输出'-'号
		mov ah, 2
		int 21h
		
		pop ax
		neg ax	; 取反+1
		jmp p
	
	prt10:
		pop ax
	p:
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
	
code ends
end start