@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\lab7\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\lab7\lab7.hex" -d "H:\CSC230_labs\lab7\lab7.obj" -e "H:\CSC230_labs\lab7\lab7.eep" -m "H:\CSC230_labs\lab7\lab7.map" "H:\CSC230_labs\lab7\numDisplay.asm"
