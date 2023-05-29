assume cs:codeseg
codeseg segment
            mov  bx, 020h
            mov  ds, bx
            mov  bx, 0
            mov  cx, 64
    s:      mov  [bx], bx
            inc  bx
            loop s
            mov  ax, 4c00h
            int  21h
codeseg ends
end