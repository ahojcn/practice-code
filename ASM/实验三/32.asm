; 密码输入及验证程序
; 要求：从键盘输入密码，
; 与程序中设定的原始密码比较，
; 若正确，显示“welcome！！”，
; 若错误，提示错误信息“wrong！！”
; 并要求再次输入，若输入3次密码错误，
; 显示“sorry！！password iswrong。”
; 并退出程序。

data segment
	password db 'ahoj'
	n equ 4	; password length
	flag db 0	; 0,1,2
	count db 3	;最大输入次数
	inputPassword db 20
		db 0
		db 20 dup(0)
	msgPassword db 'please input password:', '$'
	msgWelcome db 'welcome!',0dh,0ah, '$';flag = 0
	msgWrong db 'wrong password, try agin!',0dh,0ah,'$';flag = 1
	msgExit db 'sorry!',0dh,0ah, '$';flag = 2
data ends
	
code segment
	assume cs:code, ds:data
	
start:
	mov ax, data
	mov ds, ax
	mov es, ax

ag:
	cmp count, 0
	jz flag2
	; 输出剩余次数
	mov dl, count
	add dl, 30h
	mov ah, 2
	int 21h
	; space
	mov dl, ':'
	mov ah, 2
	int 21h
	
	; 请输入密码
	mov dx, offset msgPassword
	mov ah, 9
	int 21h

	; get password
	dec count	; count --
	lea dx, inputPassword
	mov ah, 0ah	; 1:获取并显示 8:获取字符输入不显示 0ah:获取字符串输入显示
	int 21h
	
	lea si, password
	lea di, inputPassword
	cmp byte ptr[di+1], n
	jne flag1
	add di, 2
	mov cx, n
	cld	; ->
	repe cmpsb
	jmp flag0
	
	flag1:	;flag = 1
		mov flag, 1
		jmp dealFlag
	flag2:	;flag = 2
		mov flag, 2
		jmp dealFlag
	flag0:	;flag = 0
		mov flag, 0
		jmp dealFlag
	
	dealFlag:
		cmp flag, 0
		jz WELCOME
		cmp flag, 1
		jz WRONG
		cmp flag, 2
		jz SORRY
	
	WRONG:
		call newline
		mov dx, offset msgWrong
		mov ah, 9
		int 21h
		jmp ag
	SORRY:
		call newline
		mov dx, offset msgExit
		mov ah, 9
		int 21h
		jmp EXIT
	WELCOME:
		call newline
		mov dx, offset msgWelcome
		mov ah, 9
		int 21h
		jmp EXIT
	EXIT:
		; return dos
		mov ah, 4ch
		int 21h
	
	newline proc near
		push ax
		push dx
		mov dl, 0dh
		mov ah, 2
		int 21h
		mov dl, 0ah
		mov ah, 2
		int 21h
		pop dx
		pop ax
		ret
	newline endp

code ends
end start
	
	