SSTACK SEGMENT PARA STACK 'STACK'
	DB 128 DUP(?)
SSTACK ENDS

DSEG SEGMENT PUBLIC 'DATA'

	PUBLIC X
	PUBLIC N

	X       DW		1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4
    N       EQU   	4
		
DSEG ENDS

CSEG SEGMENT 'CODE'
	ASSUME CS:CSEG, SS:SSTACK, DS:DSEG

	EXTRN OUTPUT:NEAR
	EXTRN TRANSPOSITION:NEAR


START:	
	MOV AX, DSEG
	MOV DS, AX
	
	CALL OUTPUT
	CALL TRANSPOSITION
	CALL OUTPUT
	
    
	MOV AH, 4CH
	MOV AL, 0
	INT 21H

CSEG ENDS
     END START