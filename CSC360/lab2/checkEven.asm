;Lab2
;checkEven.asm
;Mark Worrall - May 17/2016
.cseg
.org 0
	ldi r18, 0x0e
	andi r18, 0x01
	cpi r18, 0x00
	ldi r19, 0x00
	breq done
	ldi r19, 0x01

done: jmp done




