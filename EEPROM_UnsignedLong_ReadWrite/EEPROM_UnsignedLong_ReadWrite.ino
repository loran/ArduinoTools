/*
  EEPROM Unsigned Long read & write
    v1.0 - 130508
    Laurent Pantanacce
    
  Use:
    readUnsignedLongFromEEPROM(unsigned int EEPROM_address)
      read Unsigned Long (4bytes) from EEPROM address EEPROM_address
    writeUnsignedLongToEEPROM(unsigned int EEPROM_address, unsigned long value)
      write Unsigned Long (4bytes) to EEPROM address EEPROM_address
*/

#include <EEPROM.h>
#include "EEPROM_UnsignedLong_ReadWrite.h"
unsigned long n = 2444555666UL;                  // for test purpose
unsigned int  unsignedLongAddressInEEPROM = 10;  // start address in EEPROM to store/read value

void setup() {
  Serial.begin(115200); while (!Serial) { ; } // Needed for Leonardo only
  Serial.flush();
  
  Serial.println();
  Serial.println();
  Serial.println(F("EEPROM Unsigned Long read & write demo"));
  Serial.println();
  Serial.print(F("unsigned long value: "));
  Serial.print(n);
  Serial.println();
  Serial.println();
  
  Serial.println(F("EEPROM read"));
  Serial.println(F("UL stored in EEPROM: "));
  Serial.println(readUnsignedLongFromEEPROM( unsignedLongAddressInEEPROM ));
  Serial.println();
  
  Serial.println(F("EEPROM write"));
  writeUnsignedLongToEEPROM( unsignedLongAddressInEEPROM, n );
  Serial.println();

  // end 
  
}


void loop() {
   delay(1000000L);
}



