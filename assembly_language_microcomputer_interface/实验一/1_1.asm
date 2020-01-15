

      TITLE   TABLE       LOOKUP
DATA      SEGMENT
TABLE    DB     81, 78, 90, 64, 85, 76, 93, 82, 57, 80
                 DB     73, 62, 87, 77, 74, 86, 95, 91, 82, 71
NUM       DB      8
MATH     DB     ?
DATA      ENDS

STACK1  SEGMENT  PARA  STACK
                 DW   20H    DUP(0)
STACK1  ENDS 


COSEG    SEGMENT
                 ASSUME  CS:COSEG,DS:DATA,SS:STACK1
START:  MOV   AX,DATA 
                MOV    DS,AX      
                MOV    BX,OFFSET  TABLE    
           
                MOV    AL,NUM          
                DEC     AL 
XLAT TABLE                    


                MOV   MATH,AL     
                MOV   AH,4CH            
                INT      21H
COSEG  ENDS
                END   START









