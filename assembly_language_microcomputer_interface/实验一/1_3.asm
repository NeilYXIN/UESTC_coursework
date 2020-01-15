DATA      SEGMENT
BIN1         DB  35H
BIN2         DW  0AB48H
ASCBUF  DB  20H DUP(?)
DATA      ENDS

STACK1  SEGMENT PARA STACK
                 DW   20H DUP(0)
STACK1  ENDS


COSEG  SEGMENT
ASSUME CS:COSEG,DS:DATA,SS:STACK1
BEGIN:MOV AX,DATA
                 MOV DS,AX
                 MOV AH,BIN1  
                 PUSH AX             ;待转换数据压栈
                 MOV AX,8  
                 PUSH AX             ;转换位数压栈
                 LEA DI,ASCBUF
                 PUSH DI      ;存放ASCII码的首址压栈
                 CALL BINASC   ;调用转换子程序
                 MOV AX,BIN2
	  PUSH AX
	  MOV AX,10H
	  PUSH AX
                ADD DI,8
	  PUSH DI
                CALL BINASC
	  MOV  AH,4CH     
                 INT    21H

BINASC PROC
            PUSH  AX
            PUSH  CX
            PUSH  DX 
            PUSH  DI 
            MOV  BP,SP
           MOV DI,[BP+10] ;从堆栈取入口参数
            MOV CX,[BP+12]
            MOV DX,[BP+14];
LOP:  ROL DX,1
            MOV AL,DL
            AND AL,1
            ADD AL,30H
            MOV [DI],AL
             INC DI
             LOOP LOP
       POP  DI
       POP  DX
       POP  CX
       POP  AX
       RET  6    ;返回并从堆栈中弹出6个字节
BINASC ENDP
COSEG  ENDS
         END BEGIN

