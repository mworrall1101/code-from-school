;pins.asm
;learn which port is mapped to which pin and how 
;to turn it on/off
.equ PORTL = 0x10B
.equ DDRL = 0x10A
.equ PORTB = 0x25
.equ DDRB = 0x24 

	ldi r16, 0xff
	sts DDRL, r16
	sts DDRB, r16

	ldi r19, 0x02
	sts PORTL, r19

	sts PORTB, r19






