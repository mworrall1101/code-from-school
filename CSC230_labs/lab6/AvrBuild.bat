@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\lab6\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\lab6\lab6.hex" -d "H:\CSC230_labs\lab6\lab6.obj" -e "H:\CSC230_labs\lab6\lab6.eep" -m "H:\CSC230_labs\lab6\lab6.map" "H:\CSC230_labs\lab6\lab6.asm"
