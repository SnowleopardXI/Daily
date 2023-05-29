assume cs:codeseg
codeseg segment
mov ax, ffff
mov ds,ax
mov ax,2200
mov ss,ax
mov sp,0100
mov ax,[0]
add ax,[2]
mov bx,[4] 
add bx,[6]
push ax
push bx
pop ax
pop bx
push ds:[4]
push ds:[6]
codeseg ends
end