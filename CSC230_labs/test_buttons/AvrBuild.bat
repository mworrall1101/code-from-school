@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "H:\CSC230_labs\test_buttons\labels.tmp" -fI -W+ie -C V3 -o "H:\CSC230_labs\test_buttons\test_buttons.hex" -d "H:\CSC230_labs\test_buttons\test_buttons.obj" -e "H:\CSC230_labs\test_buttons\test_buttons.eep" -m "H:\CSC230_labs\test_buttons\test_buttons.map" "H:\CSC230_labs\test_buttons\buttons.asm"
