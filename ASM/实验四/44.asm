; 4-4: 程序25
; 添加功能：数组元素由用户键入。

data segment
	arr dw 0,0,0,0,0, 0,0,0,0,0
	n dw 10
	num dw 0
	msgArr db 'arr:', '$'
	msgInput db 'input:', '$'
	msgFinal db 'number of negative:', '$'
data ends

code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	
	mov dx, offset msgInput
	mov ah, 09h
	int 21h
	call getArr ;;;;;;;;;;
	; call prtNewline
	; mov dx, offset msgArr
	; mov ah, 09h
	; int 21h
	; call printArr
	call count	;;;
	call prtNewline
	
	; return dos
	mov ah, 4ch
	int 21h
	
	getNumDealSign proc near
        mov bx, 0
		mov ah, 1
		int 21h
		cmp al, '-'	; 符号
		jnz SIGN	; 不是'-'
		mov num, 1
		jmp GOGETNUM
		SIGN:	
			;sub al, 30h
			;mov ah, 0
			mov ax, 0	; clear ax -> 0
			mov bx, ax
		GOGETNUM:	
			call getNum	; getNum
			cmp num, 1	;
			jnz	EXIT
			neg bx	; 
		EXIT:
			;mov num,  bx
			ret
	getNumDealSign endp
	
	count proc near
		mov cx, n
		lea si, arr
		mov dx, 0	; 计数器清0
		t:
		mov ax, [si]
		push cx	;;;;;;;;;;;
		
		;;;
		and ax, ax
		jns nextArrNum	;不是负数（正数）
		inc dx
		;;;
		
	nextArrNum:
		add si, 2	; dw
		pop cx	;;;;;;;;;;;
		loop t
		
		push dx
		call prtNewline
		
		mov dx, offset msgFinal
		mov ah, 09h
		int 21h
		
		pop ax
		call prtDec
		ret
	count endp
	
	getArr proc near
		mov si, offset arr
		mov cx, n
		NEXTNUM:
			push cx
			call getNumDealSign
			mov [si], bx
			;mov num, bx
			;push si
			add si, 2
			pop cx
		loop NEXTNUM
		ret
	getArr endp
	
	printArr proc near
		mov cx, n
		lea si, arr
		tt:
		mov ax, [si]
		push cx	;;;;;;;;;;;
		call prtSignNum
		call prtSpace
		add si, 2	; dw
		pop cx	;;;;;;;;;;;
		loop tt
		ret
	printArr endp
	
	; 十进制带符号输出
	prtSignNum proc near
		and ax,  ax
		jns prt10	;不是负数（正数），直接输出
		;负数：取反+1，输出
		mov dl,  '-'	;输出'-'号
		mov ah,  2
		int 21h
		
		; 0110
		; 1111
		; 1001
		;xor bx,  0fh
		;inc bx	;inc 1
		;pop si
		mov ax, [si];;;;;;;;;;;;;;;;
		;mov ax,  data1
		neg ax
	
	prt10:
		;mov ax,  bx
		call prtDec
		ret
	prtSignNum endp
	
	dealSign proc near
        mov bx, 0
		mov ah, 1
		int 21h
		cmp al, '-'	; 符号
		jnz SSIGN	; 不是'-'
		mov num, 1
		jmp GGOGETNUM
		SSIGN:	
			;sub al, 30h
			;mov ah, 0
			mov ax, 0	; clear ax -> 0
			mov bx, ax
		GGOGETNUM:	
			call getNum	; getNum
			cmp num, 1	;
			jnz	EXITDEAL
			neg bx	; 
		EXITDEAL:
			mov num,  bx
			ret
	dealSign endp
	
	; 十进制输入(无符号)->bx
	getNum proc near
		mov bx,  0
		
		NEXT:
		mov ah,  1	; 获取键盘字符输入	存入al中
		int 21h
		sub al,  30h	; 减去 '0'
		jb RETEXIT	; cf == 1 && zf == 0
		cmp al,  9
		ja RETEXIT	; cf==0 && zf == 0
		cbw	; 字节转换为字 al + ax -> ax
		xchg ax,  bx	; ax <-> bx
		mov cx,  10
		mul cx	; al * cx -> ax
		xchg ax,  bx	; ax <-> bx
		add bx,  ax	; ax+bx -> bx
		jmp NEXT
		
		RETEXIT:
			ret
	getNum endp
	
	; 十进制带符号输出
	signPrtDec proc near
		and ax,  ax
		jns p10	;不是负数（正数），直接输出
		;负数：取反+1，输出
		mov dl,  '-'	;输出'-'号
		mov ah,  2
		int 21h
		
		; 0110
		; 1111
		; 1001
		;xor bx,  0fh
		;inc bx	;inc 1
		mov ax,  [si];;;;;;;;;;;;;;;;
		;mov ax,  data1
		neg ax
	
	p10:
		;mov ax,  bx
		call prtDec
		ret
	signPrtDec endp
	
	; 十进制输出->ax
	prtDec proc near
		mov cx,  0	; cx -> 0，计数器清 0
		mov bx,  10	; bx -> 10，除10
	q1:
		mov dx,  0	; dx 存余数，清0
		div bx		; dx:ax / bx ->(ax)商，(dx)余数
		xor dx,  30h	; dx ^ 110000
		push dx	; push dx，dx中存的余数，压栈
		inc cx	; cx++，计数器++
		cmp ax,  0
		jnz q1 	; 如果ax（商）不为 0 就继续上面除10操作
	q2:
		pop dx
		mov ah,  2
		int 21h
		loop q2
		ret
	prtDec endp
	
	; space
	prtSpace proc near
		push ax
		push dx
		
		mov dx, ' '
		mov ah, 2
		int 21h
		
		pop dx
		pop ax
		ret
	prtSpace endp
	
	; \n
	prtNewline proc near
		push ax
		push dx
		
		mov dx,  0ah
		mov ah,  2
		int 21h
		mov dx,  0dh
		mov ah,  2
		int 21h
		
		pop dx
		pop ax
		ret
	prtNewline endp
	
code ends
end start