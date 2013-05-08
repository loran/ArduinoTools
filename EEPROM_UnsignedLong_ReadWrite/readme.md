EEPROM Unsigned Long read & write
=================================

I was looking for 2 things:

1. to be able to simply store Unsigned Long in EEPROM without the complexity/heavyness of EEPROMWriteAnything.h
2. to be able not to write in EEPROM if value was already stored in it

So I wrote these 2 functions
    
Use
---

* readUnsignedLongFromEEPROM(unsigned int EEPROM_address): read Unsigned Long (4bytes) from EEPROM address EEPROM_address
* writeUnsignedLongToEEPROM(unsigned int EEPROM_address, unsigned long value): write Unsigned Long (4bytes) to EEPROM address EEPROM_address

Useful links
------------
Here are the most interesting links about Arduino & EEPROM
* EEPROMWriteAnything: http://playground.arduino.cc/Code/EEPROMWriteAnything
* EEPROMUtil: http://playground.arduino.cc/Code/EepromUtil
* EEPROMAnything from @SukkoPera: https://github.com/SukkoPera/Sukkino/tree/master/EEPROMAnything
* EEExplorer: https://github.com/BleuLlama/TinyBasicPlus/tree/master/EEExplorer