data segment
	ary db 17,5,40,0,67,12,34,78,32,10
	max db ?
data ends
stack1 segment para stack
	dw 20h dup(0)
stack1 ends
code segment
	assume cs:code,ds:data,ss:stack1
begin:
	mov ax,data
	mov ds,ax
	mov si,offset ary
	mov cx,9
	mov al,[si]
lop:	inc si
	cmp al,[si]
	jae biger
	mov al,[si]
biger:	loop lop
	mov max,al
	mov ah,4ch
	int 21h
code ends
	end begin