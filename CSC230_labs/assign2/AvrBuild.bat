@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\assign2\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\assign2\Assign2.hex" -d "H:\CSC230_labs\assign2\Assign2.obj" -e "H:\CSC230_labs\assign2\Assign2.eep" -m "H:\CSC230_labs\assign2\Assign2.map" "H:\CSC230_labs\assign2\a2q1.asm"
