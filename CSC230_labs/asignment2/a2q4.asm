;
; a2q4.asm
;
; Fix the button subroutine program so that it returns
; a different value for each button
;

;
; Definitions for PORTA and PORTL when using
; STS and LDS instructions (ie. memory mapped I/O)
;
.equ DDRB=0x24
.equ PORTB=0x25
.equ DDRL=0x10A
.equ PORTL=0x10B

;
; Definitions for using the Analog to Digital Conversion
.equ ADCSRA=0x7A
.equ ADMUX=0x7C
.equ ADCL=0x78
.equ ADCH=0x79


		; initialize the Analog to Digital conversion

		ldi r16, 0x87
		sts ADCSRA, r16
		ldi r16, 0x40
		sts ADMUX, r16

		; initialize PORTB and PORTL for ouput
		ldi	r16, 0xFF
		sts DDRB,r16
		sts DDRL,r16

		; This program will light up a specific LED based on the
		; button which was pressed. The buttons and the corresponding 
		; lights are:
		; RIGHT - pin 42
		; UP - pin 44
		; DOWN - pin 46
		; LEFT - pin 48
		; SELECT - pin 50
		; no button - no light
		clr r0
		call display
lp:
		call check_button
		tst r24
		breq lp
		mov	r0, r24

		call display
		ldi r20, 99
		call delay
		ldi r20, 0
		mov r0, r20
		call display
		rjmp lp

;
; An improved version of the button test subroutine
;
; Returns in r24:
;	0 - no button pressed
;	1 - right button pressed
;	2 - up button pressed
;	4 - down button pressed
;	8 - left button pressed
;	16- select button pressed
;
; this function uses registers:
;	r24
;
; if you consider the word:
;	 value = (ADCH << 8) +  ADCL
; then:
;
; value > 0x3E8 - no button pressed 	 0b00 1111 1010 00
;
; Otherwise:
; value < 0x032 - right button pressed - 0b00 0000 1100 10
; value < 0x0C3 - up button pressed		 0b00 0011 0000 11
; value < 0x17C - down button pressed	 0b00 0101 1111 00
; value < 0x22B - left button pressed	 0b00 1000 1010 11
; value < 0x316 - select button pressed  0b00 1100 0101 10
; 
; After trimming the 2 LSBS and combining ADCL and ADCH 
; into r16:
; r16 < 0x0C - R
; r16 < 0x30 - U
; r16 < 0x5F - D
; r16 < 0x8A - L
; r16 < 0xC5 - Sel
; r16 > 0xFA - no button
check_button:
		; start a2d
		lds	r16, ADCSRA	
		ori r16, 0x40
		sts	ADCSRA, r16

		; wait for it to complete
wait:	lds r16, ADCSRA
		andi r16, 0x40
		brne wait

		; read the value
		lds r16, ADCL
		lds r17, ADCH
		lsr r16
		lsr r16
		lsl r17
		lsl r17
		lsl r17
		lsl r17
		lsl r17
		lsl r17


	; put your new logic here
		or r16, r17
		; Switch: condition, button, pin#
		;if < 0C, R, 42
		cpi r16, 0x0C
		ldi r24, 0x01
		brlo endsw
		;else if < 30, U, 44
		cpi r16, 0x30
		ldi r24, 0x02
		brlo endsw
		;else if < f5, d, 46
		cpi r16, 0x5F
		ldi r24, 0x04
		brlo endsw
		;else if < 8a, l, 48
		cpi r16, 0x8A
		ldi r24, 0x08
		brlo endsw
		;else if < c5, sel, 50
		cpi r16, 0xC5
		ldi r24, 0x10
		brlo endsw
		;else if no button
		ldi r24, 0x00
endsw:


		ret

;
; delay
;
; set r20 before calling this function
; r20 = 0x40 is approximately 1 second delay
;
; this function uses registers:
;
;	r20
;	r21
;	r22
;
delay:	
del1:		nop
		ldi r21,0xFF
del2:		nop
		ldi r22, 0xFF
del3:		nop
		dec r22
		brne del3
		dec r21
		brne del2
		dec r20
		brne del1	
		ret

;
; display
; 
; display the value in r0 on the 6 bit LED strip
;
; registers used:
;	r0 - value to display
;
display:
		; copy your code from a2q2.asm here
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

