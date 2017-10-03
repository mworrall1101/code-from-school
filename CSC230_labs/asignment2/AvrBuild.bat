@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\asignment2\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\asignment2\asignment2.hex" -d "H:\CSC230_labs\asignment2\asignment2.obj" -e "H:\CSC230_labs\asignment2\asignment2.eep" -m "H:\CSC230_labs\asignment2\asignment2.map" "H:\CSC230_labs\asignment2\a2q4.asm"
