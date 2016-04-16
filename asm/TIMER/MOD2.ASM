SSTACK SEGMENT PARA STACK 'STACK'
	DB 64 DUP('STACK___')
SSTACK ENDS


CSEG SEGMENT PUBLIC 'CODE'
    ASSUME CS:CSEG, SS:SSTACK
	
	PUBLIC CLOCKS
	
CLOCKS 	PROC 

	MOV DL, 13		; переводим каретку в начало
	MOV AH, 02H
	INT 21H 

	MOV AH, 02H		; 2 функци€ прерывани€ биоса возвращает врем€
	INT 1AH	
	
	MOV BX, CX
	
	MOV CL, 4
	
	XOR AX, AX            ;дес€тки часов
	MOV AX, BX

	
	SHR AH, CL
	MOV AL, AH
       	CALL OUTPUT 
          
       	XOR AX, AX           ;единицы часов
	MOV AX, BX
	SHL AH, CL     
	SHR AH, CL
	MOV AL, AH
        CALL OUTPUT                 
          
        XOR AX, AX            ;ƒвоеточие
        MOV DL, ':'
	MOV AH, 02H
	INT 21H 
          
    XOR AX, AX            ;дес€тки минут
	MOV AX, BX
	SHR AL, CL
        CALL OUTPUT                
          
        XOR AX, AX            ;единицы минут
	MOV AX, BX
	SHL AL, CL     
	SHR AL, CL
        CALL OUTPUT 
		
	XOR AX, AX            ;ƒвоеточие
    MOV DL, ':'
	MOV AH, 02H
	INT 21H 
		
	XOR AX, AX            ;дес€тки секунд
	MOV AX, DX
	SHR AH, CL
	MOV AL, AH
        CALL OUTPUT                
          
        XOR AX, AX            ;единицы секунд
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