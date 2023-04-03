assume cs:codeseg
codeseg segment
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx
    mov ax, 0fff0h
    mov bx, 00f0h
    mov ds, ax
    xor ax, ax
    mov ax, 0
    mov al, [0]
    mov bl, [1]
    mov cl, [2]
    mov dl, [3]
    xor ax, ax
    mov ax, 4c00h
    int 21h
codeseg ends
end