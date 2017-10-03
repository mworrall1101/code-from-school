;
; a2q3.asm
;
; Write a main program that increments a counter when the buttons are pressed
;
; Use the subroutine you wrote in a2q2.asm to solve this problem.
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

; Your code here
; make sure your code is an infinite loop
		clr r0

start:	call check_button
		cpi r24, 0x00
		breq nopress
		inc r0
		ldi r20, 0x10
		call delay
nopress:call display
		jmp start


done:		jmp done		; if you get here, you're doing it wrong

;
; the function tests to see if the button
; UP or RIGHT has been pressed
;
; on return, r24 is set to be: 0 if not pressed, 1 if pressed
;
; this function uses registers:
;	r16
;	r17
;	r24
;
; This function could be made much better.  Notice that the a2d
; returns a 2 byte value (actually 12 bits).
; 
; if you consider the word:
;	 value = (ADCH << 8) +  ADCL
; then:
;
; value > 0x3E8 - no button pressed
;
; Otherwise:
; value < 0x032 - right button pressed
; value < 0x0C3 - up button pressed
; value < 0x17C - down button pressed
; value < 0x22B - left button pressed
; value < 0x316 - select button pressed
;
; This function 'cheats' because I observed
; that ADCH is 0 when the right or up button is
; pressed, and non-zero otherwise.
; 
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

		clr r24
		cpi r17, 0
		brne skip		
		ldi r24,1
skip:	ret

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
; copy your display subroutine from a2q2.asm here
 
; display the value in r0 on the 6 bit LED strip
;
; registers used:
;	r0 - value to display
;	r17 - value to write to PORTL
;	r18 - value to write to PORTB
;
;   r16 - scratch
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


