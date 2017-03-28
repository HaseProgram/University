SSTACK SEGMENT PARA STACK 'STACK'
	DB 128 DUP(?)
SSTACK ENDS

DSEG SEGMENT PUBLIC 'DATA'

	EXTRN X:WORD
	N		EQU		4
	
DSEG ENDS

CSEG SEGMENT 'CODE'
	ASSUME CS:CSEG, SS:SSTACK, DS:DSEG

	PUBLIC TRANSPOSITION

TRANSPOSITION PROC

	XOR SI,SI
	XOR BX,BX
	XOR DX, DX
	XOR AX, AX
	XOR CX, CX
	XOR DI, DI

	MOV	AL,	N-1				; количество необходимых замен
	MOV BX,	OFFSET	X		; помещаем в BX адрес нашей последовательности (BX будет указывать на элемент главной диагонали)
	
	MOV	CL,	N-1				; ранг матрицы (-1, т.к. в последней строке не будет производиться замен)
	
	EXTERNAL:
		PUSH CX				; сохраняем CX, т.к. это значение относится к внешнему циклу
		MOV	CL,	AL			; помещаем в CX количество необходимых замен, т.е. счетчик внутреннего цика
		
		MOV	DI,	6			; смещение между двумя меняемыми элементами
		MOV	SI,	1			; текущий элемент, который мы будем менять
		
		INTERNAL:
			PUSH DI
			ADD	DI,	SI		; помещаем в DI смещение относительно начала массива, указывающее на элемент, на который мы будем менять
			
			MOV	DX, [BX+SI] ; этот меняем
			XCHG DX, [BX+DI]	; меняем значения (для операци нужен один регистр, поэтому делаем через DX)
			MOV	[BX+SI], DX
			
			POP DI			; возвращаем значение DX
			
			ADD DI, 6		; добавляем к смещению 6, т.к. переход на новую строку занимает 6 байт
			INC SI			; инкрементим 2 раза SI для перехода к следующему элементу в строке
			INC SI
			LOOP INTERNAL	; переходим на начало цикла, пока CX не равняется нулю
			
		DEC AL				; уменьшаем количество необходимых замен (для каждой ноой строки будет уменьшаться)
		ADD BX, 11			; сдвигаемся на следующий элемент главной диагонали
		POP CX				; возвращаем в CX значение счетчика внешнего цикла
		LOOP EXTERNAL		; переходим на начало внешнего цикла
		
		RET
		
	
TRANSPOSITION ENDP
CSEG ENDS
     END