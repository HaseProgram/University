SSTACK SEGMENT PARA STACK 'STACK'
	DB 64 DUP('STACK___')
SSTACK ENDS


CSEG SEGMENT PUBLIC 'CODE'
    ASSUME CS:CSEG, SS:SSTACK
	
	PUBLIC CLOCKS
	
CLOCKS 	PROC 

	MOV DL, 13		; ��������� ������� � ������
	MOV AH, 02H
	INT 21H 

	MOV AH, 02H		; 2 ������� ���������� ����� ���������� �����
	INT 1AH	
	
	MOV BX, CX
	
	MOV CL, 4
	
	XOR AX, AX            ;������� �����
	MOV AX, BX

	
	SHR AH, CL
	MOV AL, AH
       	CALL OUTPUT 
          
       	XOR AX, AX           ;������� �����
	MOV AX, BX
	SHL AH, CL     
	SHR AH, CL
	MOV AL, AH
        CALL OUTPUT                 
          
        XOR AX, AX            ;���������
        MOV DL, ':'
	MOV AH, 02H
	INT 21H 
          
    XOR AX, AX            ;������� �����
	MOV AX, BX
	SHR AL, CL
        CALL OUTPUT                
          
        XOR AX, AX            ;������� �����
	MOV AX, BX
	SHL AL, CL     
	SHR AL, CL
        CALL OUTPUT 
		
	XOR AX, AX            ;���������
    MOV DL, ':'
	MOV AH, 02H
	INT 21H 
		
	XOR AX, AX            ;������� ������
	MOV AX, DX
	SHR AH, CL
	MOV AL, AH
        CALL OUTPUT                
          
        XOR AX, AX            ;������� ������
	MOV AX, DX
	SHL AH, CL    
	SHR AH, CL
	MOV AL, AH
        CALL OUTPUT 
	    
	RET	
	           
OUTPUT: 
	PUSH DX   
    
	MOV DL, AL
	ADD DL, '0'  
	
	MOV AH, 02H
	INT 21H 
	
	
	
    	POP DX  

	RET
	          
CLOCKS ENDP	
CSEG ENDS
     END	        