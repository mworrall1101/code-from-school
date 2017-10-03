@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\lab3.hex" -d "H:\CSC230_labs\lab3.obj" -e "H:\CSC230_labs\lab3.eep" -m "H:\CSC230_labs\lab3.map" "H:\CSC230_labs\blink_one_lab.asm"
