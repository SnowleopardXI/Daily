assume cs:codesg,ds:data,es:table 
data segment
          db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
          db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
          db '1993','1994','1995'
     ;以上是表示21年的21个字符串
          dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
          dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
     ;以上是表示21年公司总收的21个dword型数据
          dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
          dw 11542,14430,45257,17800
     ;以上是表示21年公司雇员人数的21个word型数据
data ends

table segment
           db 21 dup('year summ ne ?? ')
table ends
     ;计算21年中的人均收入(取整),将结果保存到table中
codesg segment
     start: 
            mov  ax,data
            mov  ds,ax
            mov  ax,table
            mov  es,ax
            mov  si,0
            mov  di,0
            mov  bx,0
            mov  cx,21

     s0:    
            mov  ax,[0000h+bx]
            mov  es:[0000h+di],ax;从ax中读入年份，写入到table中
            mov  ax,[0002h+bx]
            mov  es:[0002h+di],ax

            mov  ax,[0054h+bx]
            mov  es:[0005h+di],ax;从ax中读入公司总收入，写入到table中
            mov  dx,[0056h+bx];dx中保存的是公司总收入的高位
            mov  es:[0007h+di],dx

            mov  ax,[00a8h+si]
            mov  es:[000ah+di],ax;从ax中读入公司雇员人数，写入到table中

            mov  ax,[0054h+bx];从ax中读入公司总收入，写入到ax中
            div  word ptr [00a8h+si];将公司总收入除以公司雇员人数，结果保存在ax中
            mov  es:[000dh+di],ax;将结果保存到table中

            add  bx,4;bx指向下一个公司总收入
            add  si,2;si指向下一个公司雇员人数
            add  di,16;di指向下一个table中的年份
            loop s0
            
            mov  ax,4c00h
            int  21h
codesg ends
end start