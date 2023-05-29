assume cs:code, ds:data, ss:stack
 
data segment
         db 'bububu! bububu! '
         db 2,36,113              ;字符属性代码(十进制)
data ends
 
stack segment
          db 16 dup(0)
stack ends
 
code segment
    start:
          mov  ax,data
          mov  ds,ax
          mov  bx,0
          mov  di,16
    
          mov  ax,stack
          mov  ss,ax
          mov  sp,0
    
          mov  ax,0b800h
          mov  es,ax
          mov  si,160*12+32*2    ;将字符输出到屏幕中央
    ;(显示器可以显示25行，每行80个字符，每个字符两个字节)
    
          mov  cx,3
    s1:   
          mov  dh,ds:[di]        ;高位放属性
          push cx
          mov  cx,16
    s0:   
          mov  dl,ds:[bx]        ;低位放ASCⅡ码
          mov  es:[si],dx        ;放入缓冲区
          add  si,2
          inc  bx                ;下一个字符
          loop s0
    
          pop  cx
          inc  di
          add  si,80h            ;移动到下一行
          sub  bx,bx             ;字符串从头开始
          loop s1                ;循环3次,输出三行
    
          mov  ax,4c00h
          int  21h
code ends
end start