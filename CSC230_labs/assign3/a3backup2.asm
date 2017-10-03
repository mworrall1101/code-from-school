;Assignment 3
;A program which displays a scrolling message on two lines
;of an LCD display 
; Mark Worrall - 06/28/16


#define LCD_LIBONLY
; register r25 is reserved as a button
			  ; status register.
; The BTNREG is used to save the status of the button presses
; as well some related flags. 
; bit 0 - activation flag, is set when a button press is detected, and cleared when
; 		  no button press is detected.
; 






.cseg
.org 0x0000
		rjmp setup
.org 0x003A
		rjmp adc_isr

setup:
	call lcd_init
	call lcd_clr
	call init_strings

	ldi r16, 0b10001111
	sts ADCSRA, r16
	ldi r16, 0x40
	sts ADMUX, r16

	ldi r16, high(msg1)
	sts ptr1 + 1, r16
	ldi r16, low(msg1)
	sts ptr1, r16
	ldi r16, high(msg2)
	sts ptr2 + 1, r16
	ldi r16, low(msg2)
	sts ptr2, r16

	ldi r20, 0x20
	clr r24
.set STR1H = 0x02
.set STR1L = 0x02
.set STR2H = 0x02
.set STR2L = 0x66
	

scrolllp:
	call lcd_clr
; move 16 chars, starting from the string pointer, 
; to the line buffer
	ldi r16, STR1H
	push r16
	ldi r16, STR1L
	push r16
	lds r16, ptr1
	push r16
	lds r16, ptr1 + 1
	push r16
	ldi r16, low(line1) 
	push r16
	ldi r16, high(line1)
	push r16
	call set_line
	pop r16
	pop r16
	pop r16
	pop r16
	pop r16
	pop r16
; same for line 2	
	ldi r16, STR2H
	push r16
	ldi r16, STR2L
	push r16
	lds r16, ptr2
	push r16
	lds r16, ptr2 + 1
	push r16
	ldi r16, low(line2) 
	push r16
	ldi r16, high(line2)
	push r16
	call set_line
	pop r16
	pop r16
	pop r16
	pop r16
	pop r16
	pop r16
	


; display lines on the screen
	call display_strings

; set scroll delay

	call delay
	tst r24
	ldi r30, low(button_state)
	ldi r31, high(button_state)
	breq nopress
	st Z, r24
nopress:
	ld r24, Z
	cpi r24, 0x01
	brne skipr
	ldi r24, 0x05
	sub r20, r24
	clr r24
	st Z, r24
	jmp continue
skipr:
	cpi r24, 0x08
	brne skipl
	ldi r24, 0x05
	add r20, r24
	clr r24
	st Z, r24
	jmp continue
skipl:
	cpi r24, 0x04
	breq continue
	cpi r24, 0x02
	breq pause

continue:
; increment the string pointers
	lds r16, ptr1
	inc r16
	sts ptr1, r16
	lds r16, ptr2
	inc r16
	sts ptr2, r16


;check for the end of line 1	
	lds XH, ptr1 + 1
	lds XL, ptr1
	ld r18, X
	cpi r18, 0x00
	brne skip
	ldi r16, STR1H
	sts ptr1 + 1, r16
	ldi r16, STR1L
	sts ptr1, r16

;check for end of line 2
skip:
	lds XH, ptr2 + 1
	lds XL, ptr2
	ld r18, X
	cpi r18, 0x00
	brne skip2
	ldi r16, STR2H
	sts ptr2 + 1, r16
	ldi r16, STR2L
	sts ptr2, r16
skip2:
	jmp scrolllp

lp:	jmp lp

; A label is used fo the pause instead of a subroutine
; so that it can be called with a branch instruction
pause:
	call check_button
	tst r24
	breq nopressp
	st Z, r24
nopressp:
	ld r24, Z
	cpi r24, 0x04
	breq continue

	jmp pause
;
; END of main program
;
;

init_strings:
	;save regs
	push r16
	;move line 1 from program memory to data memory
	
	ldi r16, high(msg1)
	push r16
	ldi r16, low(msg1)
	push r16
	ldi r16, high(msg1_p<<1)
	push r16
	ldi r16, low(msg1_p<<1)
	push r16
	call str_init
	pop r16
	pop r16
	pop r16
	pop r16
	
	;move line 2 from program memory to data memory
	
	ldi r16, high(msg2)
	push r16
	ldi r16, low(msg2)
	push r16
	ldi r16, high(msg2_p<<1)
	push r16
	ldi r16, low(msg2_p<<1)
	push r16
	call str_init
	pop r16
	pop r16
	pop r16
	pop r16
	;restore regs
	pop r16
	
	ret

display_strings:
	push r16
	
	call lcd_clr 

	ldi r16, 0x00
	push r16
	push r16
	call lcd_gotoxy
	pop r16
	pop r16
	ldi r16, high(line1)
	push r16
	ldi r16, low(line1)
	push r16
	call lcd_puts
	pop r16
	pop r16

	ldi r16, 0x01
	push r16
	ldi r16, 0x00
	push r16
	call lcd_gotoxy
	pop r16
	pop r16
	ldi r16, high(line2)
	push r16
	ldi r16, low(line2)
	push r16
	call lcd_puts
	pop r16
	pop r16
	
	pop r16
	
	ret
	
display_lines:


	ret

;
;set_line START
; Takes two params off of the stack 
; Pointers stored on stack in Big Endian
; 	-lower param: the pointer to the source string
;   -upper param: the pointer to the line buffer
; Uses the following registers:
; 	XH:XL - line buffer pointer
;   YH:YL - pointer to source string
; 	r16 - multipurpose temp register
;	r17 - counter
set_line:
	push XH ;save regs
	push XL
	push YH
	push YL
	push ZH
	push ZL
	push r16
	push r17
	

	in ZH, SPH; ld Z pointer
	in ZL, SPL

	clr r17; reset counter
	ldd YH, Z+14;load X and Y with appropriate pointers
	ldd YL, Z+15
	ldd XH, Z+12
	ldd XL, Z+13
cpylp:
	ld r16, Y
	cpi r16, 0x00
	brne cont
	ldd YH, Z + 17
	ldd YL, Z + 16

cont:
	ld r16, Y+
	st X+, r16
	inc r17
	cpi r17, 0x10
	brne cpylp

	ldi r16, 0;place 0 at the end of the string
	st X, r16

	pop r17
	pop r16
	pop ZL
	pop ZH
	pop YL
	pop YH
	pop XL
	pop XH


	ret
; set_line END


; delay START
; 
; Taken from Lab 4	
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
		push r21
		push r22
		push r23
		push r20

		clr r24
del1:	nop
		ldi r21,0xFF
		tst r24
		brne del2
		call check_button
del2:	nop
		ldi r22, 0xFF
del3:	nop
		dec r22
		brne del3
		dec r21
		brne del2
		dec r20
		brne del1

		pop r20
		pop r23
		pop r22
		pop r21	
		
		ret

; delay END

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
		push r16
		lds	r16, ADCSRA	
		ori r16, 0x40
		sts	ADCSRA, r16

		; wait for it to complete
		pop r16
		ret


;adc_isr START
adc_isr:
		push r16
		push r17

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
		;else if < 5f, d, 46
		cpi r16, 0x5f
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
		pop r17
		pop r16

		reti
; adc_isr END

	msg1_p: .db "This is the message on the first line. Here it goes. ", 0
	msg2_p: .db "--- buy --- more --- pop --- buy ", 0 

.include "lcd.asm"

.dseg 
; 
; The program copies the strings from program memory 
; into data memory. 
; l1ptr and l2ptr index into these strings 
; 
msg1:
	.byte 100 
msg2:
	.byte 100 
; These strings contain the 16 characters to be displayed on the LCD
; Each time through the loop, the pointers l1ptr and l2ptr are incremented
; and then 16 characters are copied into these memory locations
line1:
	.byte 17 
line2:
	.byte 17 
; These keep track of where in the string each line currently is
ptr1:
	.byte 2 
ptr2:
	.byte 2 

button_state:
	.byte 1
