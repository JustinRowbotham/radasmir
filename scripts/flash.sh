# Flash the Fun Program

# Convert to ELF.
make

# Convert to HEX.
avr-objcopy -O ihex -R .eeprom exes/fun.elf exes/fun.hex

# Flash the program with AVRDUDE.
avrdude -p atmega2560 -c wiring -P /dev/ttyACM0 -b 115200 -D \
  -U flash:w:exes/fun.hex:i
