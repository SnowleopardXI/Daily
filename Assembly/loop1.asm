assume cs:code
code segment
    mov ax, 2000h
    mov ds, ax
    mov dx, 30h
    mov cx, 4
    mov bx, 0030
    s:mov ds:[bl], ds:[bh]
    inc bl
    inc bh
    loop s
    mov ax, 4c00h
    int 21h
code ends
end