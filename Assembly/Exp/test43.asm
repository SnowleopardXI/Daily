assume cs:code 
code segment
         mov  ax, 076ch
         mov  ds,ax
         mov  ax,0020h
         mov  es,ax
         mov  bx,0
         mov  cx,24
    s:   mov  al,[bx]
         mov  es:[bx],al
         inc  bx
         loop s
         mov  ax,4c00h
         int  21h
code ends
end
