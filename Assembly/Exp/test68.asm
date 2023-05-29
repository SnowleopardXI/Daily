assume cs:codeseg,ds:dataseg
dataseg segment
            db 'ibm             '
            db 'dec             '
            db 'dos             '
            db 'vax             '
            dw 0
dataseg ends
codeseg segment
    start:  mov  ax,dataseg
            mov  ds,ax
            mov  bx,0
            mov  cx,4
    s0:     mov  ds:[40h],cx
            mov  si,0
            mov  cx,3
    s:      mov  al,[bx+si]
            and  al,11011111b
            mov  [bx+si],al
            inc  si
            loop s
            add  bx,16
            mov  cx,ds:[40h]
            loop s0
            
            mov  ah,4ch
            int  21h
codeseg ends
end start
