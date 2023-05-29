assume cs:code 
a segment
        db 1,2,3,4,5,6,7,8
a ends

b segment
        db 1,2,3,4,5,6,7,8
b ends

ca segment
        db 0,0,0,0,0,0,0,0
ca ends

code segment
      start:
      ;补充编写code段中的内容，将a段和b段中的数据依次相加，将结果存到c段中
            mov  ax, a
            mov  ds, ax
            mov  ax, b
            mov  es, ax
            xor  bx, bx
            mov  cx, 8
      s:    mov  dl, [bx]
            add  dl, es:[bx]
            push ds
            mov  ax, ca
            mov  ds, ax
            mov  [bx], dl
            pop  ds     
            inc  bx
            loop s
            mov  ax, 4c00h
            int  21h

code ends
end start 