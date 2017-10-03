;
; lab 5
; 

.include "m2560def.inc"

.cseg

	ldi ZH,high(msg<<1)	; initialize index register Z to point to msg in flash memory
	ldi ZL,low(msg<<1) ;why msg<<1

	;write you code here, initialize index register X to point to msg_copy in SRAM
	ldi XH, high(msg_copy)
	ldi XL, low(msg_copy)

	ldi r16, -1		;initialize counter to 0		

next_char:
	;write you code here
	;write a loop, copy each character from flash memory to at msg_copy in SRAM
	;get the length of the string, store it at str_len in SRAM
lp:	lpm r17, Z+
	st X, r17
	adiw XH:XL, 0x01
	inc r16
	cpi r17, 0
	brne lp
	
	sts str_len, r16



done:	jmp done

msg: .db "Hello, world!", 0 ; c-string format

.dseg
.org 0x200
msg_copy: .byte 14
str_len: .byte 1

