; 5
data segment
	dat1 dw 13h
data ends

code segment
	assume cs:code, ds:data
start:
	mov ax, data
	mov ds, ax
	
	
	;call newline
	
	mov ax, dat1
	
	call count
	
	;mov ax, dat1
	call prt1
	;call newline ;调用回车换行子函数
	;mov ax, dat1
	call prt2
	;call newline
	;mov ax, dat1
	mov bx, dat1
	call prt3
	;mov ax, 4c00h
	
	; return dos
	mov ah, 4ch
	int 21h
	
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
	
	;统计1的个数
	count proc near
		mov bx, dat1
		mov cx, 0
		mov cx, 16
		mov dx, 0h
		
	T:  
		shl bx, 1 ;逻辑左移
		jnc c2
	c1:	inc dl
	c2: 
		loop T
		
		mov bx, dx
		call prt3
		;add dl, 30h
		mov ah, 2
		int 21h
		
		call newline
	count endp
	
	;以2进制形式输出
	prt1 proc near
		mov bx, dat1
		mov cx, 16
		
	T1: rol bx,1 ;循环左移
		mov dl,bl
		and dl,01h
		add dl,30h
		mov ah,2
		int 21h
		loop T1
		
		mov dl,'B'
		mov ah,2
		int 21h
		
		call newline;输出完，回车换行
		
	prt1 endp



	;以16进制形式输出
	prt2 proc near
		mov bx,dat1 ;B
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
		call newline	;输出完，回车换行
	prt2 endp


	;以十进制方式输出
	prt3 proc near
		mov ax, bx
		xor cx, cx
		mov bx, 10
	q0:
		xor dx, dx
		div bx
		xor dx, 0e30h
		push dx
		inc cx
		cmp ax, 0
		jnz q0
	q1:
		pop ax
		int 10h
		loop q1
		int 21h
		
		mov dl, 'D'
		mov ah, 2
		int 21h
		call newline;输出完，回车换行
	prt3 endp
	
	
code ends
ends start