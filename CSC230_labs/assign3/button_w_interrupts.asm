;
; button.asm
;
; A program that demonstrates reading the buttons
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
.equ ADCSRB=0x7B
.equ TCCR0A=0x44
.equ TCCR0B=0x45
.equ OCR0A=0x47
.equ TCNT1H=0x85
.equ TCNT1L=0x84
.equ TCCR1A=0x80
.equ TCCR1B=0x81
.equ TIMSK1=0x6F
.def BTNREG=r25; register r25 is reserved as a button
			  ; status register.
; The BTNREG is used to save the status of the button presses
; as well some related flags. 
; bit 0 - activation flag, is set when a button press is detected, and cleared when
; 		  no button press is detected.
; 
.org 0x0000
	jmp setup

.org 0x0028
	jmp timer_isr

.org 0x003A
	jmp ADC_isr



	
	
		; initialize the Analog to Digital conversion

setup:	ldi r16, 0b10001111
		sts ADCSRA, r16
		ldi r16, 0x40
		sts ADMUX, r16
		call timer_init

	
	


		; initialize PORTB and PORTL for ouput
		
		ldi	r16, 0xFF
		sts DDRB,r16
		sts DDRL,r16

		sei
lp:			
		ldi r16, 0b10100000
		lds r17, PORTL
		eor r17, r16
		sts PORTL, r17
		ldi r20, 0x30
		call delay

		


		rjmp lp


ADC_isr:

	push r16
	push r17
;	lds r16, SREG
;	push r16


	lds r16, ADCL
	lds r17, ADCH
	cpi r17, 0x03
	brsh clearflag
	ldi r16, 0x01
	and r16, BTNREG;check the activation flag (bit 0 in BTNREG)
	cpi r16, 0x00
	brne adcdone
	ori BTNREG, 0x01
	ldi r16, 0b00001010
	lds r17, PORTB
	eor r17, r16

	sts PORTB, r17
	jmp adcdone
clearflag:
	ldi r17, 0x01
	cbr BTNREG, 0x01
adcdone:
;	pop r16
;	sts SREG, r16

	pop r17
	pop r16

	reti

timer_init:

	push r16
	ldi r16, 0x00
	sts TCNT1H, r16
	sts TCNT1L, r16
	sts TCCR1A, r16
	ldi r16, 0x02  ; This affects frequency of ADC
	sts TCCR1B, r16; check(1-v.fast, 5-v.slow, 3 seems to work)
	ldi r16, 0x01
	sts TIMSK1, r16
	pop r16 

	ret

timer_isr:
		push r16
		lds	r16, ADCSRA	
		ori r16, 0x40
		sts	ADCSRA, r16

		pop r16

		reti
;
; the function tests to see if the button
; UP or SELECT has been pressed
;
; on return, r24 is set to be: 0 if not pressed, 1 if pressed
;
; this function uses registers:
;	r16
;	r17
;	r24
;
; This function could be made much better.  Notice that the a2d
; returns a 2 byte value (actually 10 bits).
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


		; read the value



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
;write the delay function here

		push r21
		push r22

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

		pop r22
		pop r21

		ret
