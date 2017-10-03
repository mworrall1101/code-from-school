@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\lab2\labels.tmp" -fI -W+ie -C V3 -o "H:\lab2\lab2.hex" -d "H:\lab2\lab2.obj" -e "H:\lab2\lab2.eep" -m "H:\lab2\lab2.map" "H:\lab2\checkEven2.asm"
