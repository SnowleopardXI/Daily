assume cs:codeseg
codeseg segment
            mov  ax, 0h
            mov  ds, ax
            mov  bx, 200h
            mov  cx, 40h
            mov  dx, 0
    s:      mov  ds:[bx], bl
            inc  bx
            inc  dl
            loop s
            mov  ax, 4c00h
            int  21h
codeseg ends
end