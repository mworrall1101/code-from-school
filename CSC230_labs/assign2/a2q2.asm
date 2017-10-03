;
; a2q2.asm
;
;
; Turn the code you wrote in a2q1.asm into a subroutine
; and then use that subroutine with the delay subroutine
; to have the LEDs count up in binary.
;
;
; These definitions allow you to communicate with
; PORTB and PORTL using the LDS and STS instructions
;
.equ DDRB=0x24
.equ PORTB=0x25
.equ DDRL=0x10A
.equ PORTL=0x10B


; Your code here
; Be sure that your code is an infite loop

		ldi r16, 0xFF
		sts DDRB, r16		; PORTB all output
		sts DDRL, r16		; PORTL all output

		ldi r16, 0x3F		; display the value
mainlp:	mov r0, r16			; in r0 on the LEDs
		call display
		ldi r20, 0x10
		call delay
		inc r16
		cpi r16, 0x40
		breq reset
		jmp mainlp

reset: 	clr r16
		jmp mainlp


done:		jmp done	; if you get here, you're doing it wrong

;
; display
; 
; display the value in r0 on the 6 bit LED strip
;
; registers used:
;	r0 - value to display
; 	r1 - PORTB mask
;	r2 - PORTL mask
; 	r17 - bit incrementing
;	r18 - counter
;	r19 - comparisons
;	r20 - pop/compare register
display:

		ldi r17, 0x01
		clr r18
		clr r1
		clr r2
	
displp:	mov r19, r17		;the first loop is used to load the bit
		and r19, r0			;values onto the stack
		push r19
		inc r18
		lsl r17
		cpi r18, 0x06
		brne displp

		clr r18				;this part of the program pops the values
		ldi r17, 0b00000010	;off of the stack and uses "or" to add them 
		pop r20				;to their respective registers
		cpi r20, 0x00
		breq skip4
		or r1, r17
skip4:	lsl r17
		lsl r17
		pop r20
		cpi r20, 0x00
		breq skip2
		or r1, r17
skip2:	ldi r17, 0b00000010
displp2:pop r20
		cpi r20, 0x00
		breq skip3
		or r2, r17
skip3:  lsl r17
		lsl r17
		inc r18
		cpi r18, 0x04
		brne displp2
		
		mov r17, r1
		mov r18, r2
		sts PORTB, r17
		sts PORTL, r18


		ret
;
; delay
;
; set r20 before calling this function
; r20 = 0x40 is approximately 1 second delay
;
; registers used:
;	r20
;	r21
;	r22
;
delay:	
del1:	nop
		ldi r21,0xFF
del2:	nop
		ldi r22, 0xFF
del3:	nop
		dec r22
		brne del3
		dec r21
		brne del2
		dec r20
		brne del1	
		ret
