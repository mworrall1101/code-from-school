;Assignment 3
;A program which displays a scrolling message on two lines
;of an LCD display 
; Mark Worrall - 06/28/16

#define LCD_LIBONLY
.include "lcd.asm"

.cseg

	call lcd_init
	call lcd_clr
	call init_strings
	ldi r16, high(msg1)
	sts ptr1 + 1, r16
	ldi r16, low(msg1)
	sts ptr1, r16
	ldi r16, high(msg2)
	sts ptr2 + 1, r16
	ldi r16, low(msg2)
	sts ptr2, r16

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
	ldi r20, 0x20
	call delay

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
		
		pop r23
		pop r22
		pop r21	
		
		ret

; delay END
	

	msg1_p: .db "This is the message on the first line. Here it goes. ", 0
	msg2_p: .db "--- buy --- more --- pop --- buy ", 0 
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
