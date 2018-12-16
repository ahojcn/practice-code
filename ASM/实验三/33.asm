; 数据输入程序
; 要求从键盘输入一个十进制数（无符号数）并在屏幕上显示输出。

data segment
	num dw 0
data ends

code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	
	call getNum
	mov num, bx
	
	call newline
	mov ax, num
	call fun
	
	; return dos
	mov ah, 4ch
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
	
	getNum proc near
		mov bx, 0
		NEXT:
		mov ah, 1	; 获取键盘字符输入	存入al中
		int 21h
		sub al, 30h	; 减去 '0'
		jb EXIT	; cf == 1 && zf == 0
		cmp al, 9
		ja EXIT	; cf==0 && zf == 0
		cbw	; 字节转换为字 al + ax -> ax
		xchg ax, bx	; ax <-> bx
		mov cx, 10
		mul cx	; al * cx -> ax
		xchg ax, bx	; ax <-> bx
		add bx, ax	; ax+bx -> bx
		jmp NEXT
		
		EXIT:
			ret
	getNum endp
	
	newline proc near
		mov dx, 0ah
		mov ah, 2
		int 21h
		mov dx, 0dh
		mov ah, 2
		int 21h
		ret
	newline endp
	
	
code ends
end start