ArduinoTools
============

This is a collection of libraries/code snippets for the Arduino platform.
I originally wrote them for my own projects.
They may be useful to others.


EEPROM Unsigned Long read & write
---------------------------------

Read & Write Unsigned Long in EEPROM

* readUnsignedLongFromEEPROM(byte EEPROM_address): read Unsigned Long (4bytes) from EEPROM address EEPROM_address
* writeUnsignedLongToEEPROM(unsigned long value, byte EEPROM_address): write Unsigned Long (4bytes) to EEPROM address EEPROM_address