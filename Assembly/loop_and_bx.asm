assume cs:codeseg
codeseg segment
    mov ax, 0ffffh
    mov ds, ax
    xor bx, bx
    xor dx, dx
    mov cx, 12
    xor ax, ax
    s:  mov al,[bx]
        mov ah, 0
        add dx, ax
        inc bx
    loop s

    mov ax, 4c00h
    int 21h
codeseg ends
end