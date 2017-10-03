.cseg
.org 0
	ldi r18, 0x09
	andi r18, 0x01

	ldi r19, 0x00
	breq done
	ldi r19, 0x01

done: jmp done
