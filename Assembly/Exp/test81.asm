assume cs:codeseg
codeseg segment
    mov ax,4c00h;0000
    int 21h;0003
    start :mov ax,0;0005
    s:nop;0008
    nop;0009

    mov di,offset s;000a
    mov si,offset s2;000d
    mov ax,cs:[si];0010
    mov cs:[di],ax;0014

    s0:jmp short s;0016
    s1:mov ax,0;0018
    int 21h;001b
    s2:jmp short s1;001d
    nop;001f
codeseg ends
end start