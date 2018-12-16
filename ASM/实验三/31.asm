; 冒泡排序
; 在数据段定义一个数组，
; 其中存放若干个dw类型数据，
; 编写冒泡排序程序，
; 并输出排序前后数组中各元素值。

data segment
	arr dw 100,11,55,44,33,22,99,12,5,65
	n equ 10	; 常量
	msg1 db 'before sort:', '$'
	msg2 db 'after sort:', '$'
	msg3 db 'sorting:', '$'
data ends

code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	
	; 输出数组元素
	mov dx, offset msg1
	mov ah, 09h
	int 21h
	call newline
	call printArr ;;;;;;
	call newline
	
	; sort
	mov dx, offset msg3
	mov ah, 09h
	int 21h
	call bobSort ;;;;;;;
	mov dx, offset msg2
	mov ah, 09h
	int 21h
	call newline
	call printArr ;;;;;;;;
	
	;return dos
	mov ah, 4ch
	int 21h
	
	
	bobSort proc near
	mov cx, 10
	w1: ; for i
		push cx
		lea si, arr
		mov cx, 10
		w2: ; for j
			mov ax, [si]
			cmp ax, [si+2] 	; a[j] a[j+1]
			jbe nextNum		; a[j] < a[j+1] -> nextNum
							; else(a[j]>a[j+1])
			xchg ax, [si+2]	; a[j+1] -> ax
			mov [si], ax	; a[j] -> ax
		nextNum:
			add si, 2
			loop w2
		call newline
		call printArr
		pop cx
		loop w1
	bobSort endp
	
	
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