data segment
dat1 dw 13h
data ends

code segment
	assume cs:code, ds:data
start:
  mov ax, data
  mov ds, ax
 
  mov ax, dat1
  call print
  mov ax, 4c00h
  int 21h
 
print proc near
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
  ret
print endp
code ends
end start