@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\lab8\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\lab8\lab8.hex" -d "H:\CSC230_labs\lab8\lab8.obj" -e "H:\CSC230_labs\lab8\lab8.eep" -m "H:\CSC230_labs\lab8\lab8.map" "H:\CSC230_labs\lab8\timers_interrupt.asm"
