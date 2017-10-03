; Assignment 3
;
; A program which displays a scrolling message on two lines
; of an LCD display.
;
; Button Functionality:
; 	up - pause scrolling
; 	down - resume scrolling
; 	left - increase scroll speed
; 	     - increases LEDs toward pin 42(PORTL bit7)
; 	right - decrease scroll speed
; 	      - decreases LEDs toward pin 52(PORTB bit1)
; 	select - change display message
; 		   - displays and then reverts back to main scrolling message 
;		     after a short delay
;  
; This program is designed with the assumption that the button
; activation ranges are:
; 
; value = (ADCH << 8) +  ADCL
;
; value > 0x3E8 - no button pressed 	 0b00 1111 1010 00
;
; Otherwise:
; value < 0x032 - right button pressed - 0b00 0000 1100 10
; value < 0x0C3 - up button pressed	   - 0b00 0011 0000 11
; value < 0x17C - down button pressed  - 0b00 0101 1111 00
; value < 0x22B - left button pressed  - 0b00 1000 1010 11
; value < 0x316 - sel button pressed   - 0b00 1100 0101 10 
;
;
; Author: Mark Worrall - 07/11/16

#define LCD_LIBONLY

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

	ldi r16, 0xFF
	out DDRB, r16
	sts DDRL, r16
	ldi r16, 0x0A
	sts PORTL, r16


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
	sei
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

; delay subroutine also checks for a button push
	call delay
	tst r24
	ldi r30, low(button_state)
	ldi r31, high(button_state)
	breq nopress
	st Z, r24
nopress:
	ld r24, Z
	cpi r24, 0x10 ; select pressed
	brne skipsel  ; display "under maintenance" alternate message
	call alt_display
	clr r24
	st Z, r24
	jmp continue
skipsel:
	cpi r24, 0x01 ; right pressed
	brne skipr    ; reduce delay, speed up scroll
	ldi r24, 0x05
	sub r20, r24
	call inc_led
	clr r24
	st Z, r24
	jmp continue
skipr:
	cpi r24, 0x08 ; left pressed
	brne skipl    ; increase delay, slow down scroll
	ldi r24, 0x05
	add r20, r24
	call dec_led
	clr r24
	st Z, r24
	jmp continue
skipl:
	cpi r24, 0x04 ; down press
	breq continue
	cpi r24, 0x02 ; up press, branch to pause label to pause scroll
	breq pause

continue:
; increment the string pointers
	lds r16, ptr1
	inc r16
	sts ptr1, r16
	lds r16, ptr2
	inc r16
	sts ptr2, r16


; check for the end of line 1	
	lds XH, ptr1 + 1
	lds XL, ptr1
	ld r18, X
	cpi r18, 0x00 ; when string pointer reaches the "null terminator",
	brne skip     ; reset the pointer to the saved start of string location
	ldi r16, STR1H
	sts ptr1 + 1, r16
	ldi r16, STR1L
	sts ptr1, r16

; check for end of line 2
; same end of line process as for line 1
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

; PAUSE label is used fo the pause instead of a subroutine
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
; ***END of main program***
;


; alt_display START
; *****************
; Displays an alternate message when the select button is pressed, and reverts
; back to main message after a short delay.
; Currently is a placeholder for future functionality
; 
; Registers Used:
; 	r16 - multi function
;	r30,r31 - pointer to the button_state stored in memory
;	r24 - used as the return register
alt_display:
	
	push r16
	push r30
	push r31
	push r24
	clr r24
	ldi r30, low(button_state)
	ldi r31, high(button_state)
	st Z, r24
altlp:
	call lcd_clr 

	ldi r16, 0x00
	push r16
	push r16
	call lcd_gotoxy
	pop r16
	pop r16
	ldi r16, high(alt_msg1)
	push r16
	ldi r16, low(alt_msg1)
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
	ldi r16, high(alt_msg2)
	push r16
	ldi r16, low(alt_msg2)
	push r16
	call lcd_puts
	pop r16
	pop r16

	call delay
	call delay
	call delay
	call delay
	call delay
	call delay

; ***(This is remnant code from previous and possibly future functionality)***	
; Test for select press and return to main message if pressed
;	tst r24
;	breq altnopress
;	st Z, r24
;altnopress:
;	ld r24, Z
;	cpi r24, 0x10
;	breq altend
;	clr r24
;	st Z, r24
;	jmp altlp
; ***(This is remnant code from previous and possibly future functionality)***	


altend:
	pop r24
	pop r31
	pop r30
	pop r16	
	
		ret
;
; ***END alt_display
;



; init_strings START
; ******************
; Moves all strings from program memory into data memory.
; Uses the str_init subroutine from the lcd.asm library.
; Registers:
;	r16 - multifunction
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

	
	;move alternate message 1 from program memory to data memory
	
	ldi r16, high(alt_msg1)
	sts alt_ptr1+1, r16
	push r16
	ldi r16, low(alt_msg1)
	sts alt_ptr1, r16
	push r16
	ldi r16, high(alt_msg1_p<<1)
	push r16
	ldi r16, low(alt_msg1_p<<1)
	push r16
	call str_init
	pop r16
	pop r16
	pop r16
	pop r16

	;move alternate message 2 from program memory to data memory
	
	ldi r16, high(alt_msg2)
	sts alt_ptr2+1, r16
	push r16
	ldi r16, low(alt_msg2)
	sts alt_ptr2, r16
	push r16
	ldi r16, high(alt_msg2_p<<1)
	push r16
	ldi r16, low(alt_msg2_p<<1)
	push r16
	call str_init
	pop r16
	pop r16
	pop r16
	pop r16

	;restore regs	
	pop r16
	ret
;
; ***END init_strings
; 

;
; display_strings START
; *********************
; Displays the strings currently stored in line1 and line2
; Uses lcd_gotoxy and lcd_puts subroutines from the lcd.asm library
; Register:
;	r16 - multifunction 
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
;
; ***END display_strings 
;
	


;
; set_line START
; **************
; Takes two params off of the stack 
; Pointers stored on stack in Big Endian
; 	-lower param: the pointer to the source string
;   -upper param: the pointer to the line buffer
; Registers:
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
;
; ***END set_line
;


; delay START
; ***********
; Taken from Lab 4	
; set r20 before calling this function
; r20 = 0x40 is approximately 1 second delay
; Calls check_button to check for a button push
;
; this function uses registers:
;
;	r20
;	r21
;	r22
;	r24 - return register
delay:
		push r21
		push r22
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
		pop r22
		pop r21	
		
		ret
;
; ***END delay
;


; check_button START
; ******************
; An improved version of the button test subroutine
; Also initiates the ADC conversion. The ADC conversion complete interrupt service
; routine is used to determine which button was pressed, if any.
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
; After combining ADCL and ADCH into r16 and trimming the 2 LSBs 
; 
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


; adc_isr START
; *************
; Is called after the completion of the adc conversion, and is used 
; to determine which button was pressed if any.
; Registers:
;	r16, r17 - used to store the value returned by the ADC
; 
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
;		cpi r16, 0x
		ldi r24, 0x10
		brlo endsw
		;else if no button
		ldi r24, 0x00
endsw:
		pop r17
		pop r16

		reti
;
; ***END adc_isr

; inc_led START
; *************
; Used to change the LED when the scroll speed is increased
; Registers:
;	r16 - multipurpose
;
inc_led:

		push r16
		
		lds r16, PORTL
		cpi r16, 0x80
		breq inc_led_done
		cpi r16, 0x00
		breq bchk
		cpi r16, 0x02
		brne lchk
		ldi r16, 0x0A
		sts PORTL, r16
		jmp inc_led_done
lchk:	
		cpi r16, 0x0A
		brne lchk2
		ldi r16, 0x08
		sts PORTL, r16
		jmp inc_led_done
lchk2:
		cpi r16, 0x08
		brlo bchk
		lsl r16
		lsl r16
		sts PORTL, r16
		
bchk:
		in r16, PORTB
		cpi r16, 0x08
		brne bchk2
		ldi r16, 0x00
		out PORTB, r16
		ldi r16, 0x02
		sts PORTL, r16
		jmp inc_led_done
bchk2: 
		cpi r16, 0x02
		brne inc_led_done
		lsl r16
		lsl r16
		out PORTB, r16

inc_led_done:
		pop r16
		ret
;
; ***END inc_led
; 


;
; dec_led START
; *************
; Same as inc_led but for speed decrease.
; Registers:
;	r16 - mutlipurpose
;
dec_led:
		push r16

		lds r16, PORTL
		cpi r16, 0x00
		breq bchkd
		cpi r16, 0x80
		breq L80
		cpi r16, 0x20
		breq L20
		cpi r16, 0x08
		breq L08
		cpi r16, 0x0A
		breq L0A
		cpi r16, 0x02
		breq L02

L80:
		ldi r16, 0x20
		sts PORTL, r16
		jmp dec_led_done
L20:
		ldi r16, 0x08
		sts PORTL, r16
		jmp dec_led_done
L08:
		ldi r16, 0x0A
		sts PORTL, r16
		jmp dec_led_done
L0A:
		ldi r16, 0x02
		sts PORTL, r16
		jmp dec_led_done
L02:
		ldi r16, 0x00
		sts PORTL, r16
		ldi r16, 0x08
		out PORTB, r16 
		jmp dec_led_done

bchkd:
		in r16, PORTB
		cpi r16, 0x02
		breq dec_led_done
		lsr r16
		lsr r16
		out PORTB, r16
dec_led_done:
		pop r16

		ret
;
; ***END dec_led
;


	msg1_p: .db "This is the message on the first line. Here it goes. ", 0
	msg2_p: .db "--- buy --- more --- pop --- buy ", 0 

	alt_msg1_p: .db "Feature Under ",0
	alt_msg2_p: .db "Maintenance", 0

; This is the library which contains all the LCD subroutines
.include "lcd.asm"

.dseg 

; 
; The program copies the strings from program memory 
; into data memory. 
; ptrs are used to track scrolling 
; 
msg1:
	.byte 100 
msg2:
	.byte 100 
alt_msg1:
	.byte 50
alt_msg2:
	.byte 50

; These strings contain the 16 characters to be displayed on the LCD
; Each time through the loop, the pointers ptr1 and ptr2 are incremented
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
alt_ptr1:
	.byte 2
alt_ptr2:
	.byte 2
; This is used to store the button which has been pressed.
; Must be cleared manually when the info is no longer needed.
button_state:
	.byte 1
