StacSeg SEGMENT PARA STACK 'STACK'
	DW	128h DUP (?)
StacSeg  ENDS

CodeSeg SEGMENT PUBLIC 'CODE'
     ASSUME CS:CodeSeg, SS:StacSeg
	
	PUBLIC Main
	EXTRN Time:NEAR

Main:	MOV AX, 0
          
       	INT 16H		;читаем скан код нажатой клавиши
                                         
	CMP AH, 02H ;1
	JZ Time
	CMP AH, 03H ;2
	JZ Time
	CMP AH, 04H ;3
	JZ Time
	CMP AH, 05H ;4
	JZ Time
	CMP AH, 06H ;5
	JZ Time
	CMP AH, 07H ;6
	JZ Time
	CMP AH, 08H ;7
	JZ Time
	CMP AH, 09H ;8
	JZ Time
	CMP AH, 0AH ;9
	JZ Time
	CMP AH, 0BH ;0
	JZ Time

	CMP AH, 01H 	    
        JNZ Main              ;если не нажато ESC,


	MOV AH, 4CH
	MOV AL, 0
	INT 21H


CodeSeg ENDS
     END Main
