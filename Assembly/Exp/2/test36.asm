assume cs:code 
a segment
      dw 1,2,3,4,5,6,7,8,9,0ah,0bh,0ch,0dh,0eh,0fh,0ffh
a ends
b segment
      dw 0,0,0,0,0,0,0,0
b ends

code segment
    start:
    ;用push指令将a段中前8个字型数据逆序存储到b段中
    mov ax,a
    mov ds,ax
    mov ax,b
    mov ss,ax
    mov sp,16
    mov bx,0
    mov cx,8
    s:push ds:[bx]
    add bx,2
    loop s
    mov ax,4c00h
    int 21h
code ends
end start 
