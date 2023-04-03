assume cs:codeseg
codeseg segment
    dw 0123h,0456h,0789h,0ABCh,0DEFh,0FEDh,0CBAh,0987h
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    start:mov ax, cs
    mov ss,ax
    mov sp, 30h
    mov bx,0
    mov cx,8
    s:push cs:[bx]
    add bx,2
    loop s
    mov bx,0
    mov cx,8
    s1:pop cs:[bx]
    add bx,2
    loop s1
    mov ax,4c00h
    int 21h
codeseg ends
end start