; 在数组中查找并删除数据程序
; 要求：在数据段定义一个数组，其中存放若干个dw类型数据，
; 从键盘输入一个十进制数，在数组中查找该数据，
; 若未找到，显示“no find！！”，
; 若找到，显示“find！！”，
; 并在数组中删除该数据，
; 将删除数据后的数组在屏幕显示。

data segment
	len equ 18
	arr dw 1,11,55,22,44,33,21,9,0,40
	n dw 10
	num dw 0
	msgInput db 'please input a number:', '$'
	msgFind db 'find!', '$'
	msgNotFind db 'not find', '$'
data ends

code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	
	; please input a number:
	mov dx, offset msgInput
	mov ah, 09h
	int 21h
	; get num
	call getNum
	mov num, bx
	push bx
	call printArr
	call newline
	call findAndDelNum ;;;
	call printArr
	
	; return dos
	mov ah, 4ch
	int 21h
	
	findAndDelNum proc near
		lea si, arr
		mov ax, num
		mov cx, n
		T:
			mov bx, [si]
			cmp ax, [si]
			;call prtDec
			;call space
			jz DELNUM
			;; test
			; push ax
			; mov ax, [si]
			; call prtDec
			; pop ax
			; call newline
			;; test
			add si, 2
		loop T
		DELNUM:
			; [si]->55 [si+2]->22 [si+len]->22
			; [si+2] -> 要查找的数字
			
			; 看看有没有找到
			cmp cx, 0
			jnz FINDIT
			
			; not find
			mov dx, offset msgNotFind
			mov ah, 09h
			int 21h
			;call newline
			; return dos
			mov ah, 4ch
			int 21h
			
			FINDIT:
			mov dx, offset msgFind
			mov ah, 09h
			int 21h
			call newline
			
			push si	;save now [si]
			; find the last one
			dec cx
			mov cx, cx
			cmp cx, 0
			jz CHG
			FINDEND:
				add si, 2
			loop FINDEND
			
			CHG:
			; change [si], last one
			mov bx, [si]	; mov last one -> bx
			pop si	; pop now [si]
			mov [si], bx
			
			dec n	; n--
			;;; test
			;mov ax, [si+18]
			;mov ax, [si+2]
			;call prtDec
			;call newline
			;mov ax, [si]
			;call prtDec
			;call newline
			;;; test
		ret
	findAndDelNum endp
	
	printArr proc near
		mov cx, n
		lea si, arr
		tt:
		mov ax, [si]
		push cx	;;;;;;;;;;;
		call prtDec
		call space
		add si, 2	; dw
		pop cx	;;;;;;;;;;;
		loop tt
		ret
	printArr endp
	
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
	
	; num -> ax
	prtDec proc near
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
	prtDec endp
	
	;空格
	space proc near
		mov dl, 20h
		mov ah, 2
		int 21h
		ret
	space endp
	
	; \n
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