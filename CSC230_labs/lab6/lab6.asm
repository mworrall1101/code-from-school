;
; lab6.asm
;

; An example to illustrate passing parameters via
; the stack.
;

; The stack pointer is in I/O space, so if we 
; want to use LDS and STS instructions we have to
; use the alternate addresses.
;
; SPH is 0x3E if using IN/OUT and 0x5E if using LDS/STS
; SPL is 0x3D if using IN/OUT and 0x5D if using LDS/STS
;
.equ SPH=0x5E
.equ SPL=0x5D

;
; The Z register is the combination of
; R30:R31
;
.def XH=r27
.def XL=r26
.def YH=r29
.def YL=r28
.def ZH=r31
.def ZL=r30
	; initialize the stack pointer
.cseg
	ldi r16, 0xFF
	sts SPL, r16
	ldi r16, 0x21
	sts SPH, r16
		
	;call subroutine void strcpy(src, dest)
	;push 1st parameter - src address
	ldi r16, high(src << 1)
	push r16
	ldi r16, low(src <<1)
	push r16

	;push 2nd parameter - des address
	ldi r16, high(dest)
	push r16
	ldi r16, low(dest)
	push r16

	call strcpy
	pop ZL
	pop ZH
	pop r16
	pop r16

	;call subroutine int strlen(string dest)
	;return value is in r24
	;push parameter dest, in register Z already
	push ZH
	push ZL
	call strlength
	pop ZL
	pop ZH
	sts length, r24

done: jmp done

strcpy:
	push r30
	push r31
	push r29
	push r28
	push r26
	push r27
	push r23
	LDS YH, SPH ;SP in Y
	LDS YL, SPL
	ldd ZH, Y + 14
	ldd ZL, Y + 13
	ldd XH, Y + 12
	ldd XL, Y + 11

next_char:
	lpm r23, Z+
	st X+, r23
	tst r23
	brne next_char
	pop r23
	pop r27
	pop r26
	pop r28
	pop r29
	pop r31
	pop r30
	ret

strlength:
	;write your code here
	push r23
	clr r24
countlp:
	ld r23, Z+
	inc r24
	tst r23
	brne countlp
	pop r23
	ret

src: .db "Hello, world!", 0 ; c-string format

.dseg
.org 0x200
dest: .byte 14
length: .byte 1
