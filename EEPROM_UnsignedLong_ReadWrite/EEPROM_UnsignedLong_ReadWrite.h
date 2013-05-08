/*
  EEPROM Unsigned Long read & write
    v1.0 - 130508
    Laurent Pantanacce
    
  Use:
     readUnsignedLongFromEEPROM(byte EEPROM_address)
         read Unsigned Long (4bytes) from EEPROM address EEPROM_address
     writeUnsignedLongToEEPROM(unsigned long value, byte EEPROM_address)
         write Unsigned Long (4bytes) to EEPROM address EEPROM_address
*/
#ifndef EEPROM_UnsignedLong_ReadWrite_h
#define EEPROM_UnsignedLong_ReadWrite_h
#include <Arduino.h>
#include <EEPROM.h>

#define  DEBUG_EEPROM               // comment to disable DEBUG mode

unsigned long readUnsignedLongFromEEPROM(unsigned int EEPROM_address){
  // read 4 bytes from EEPROM starting at address provided
  // then recreate Unsigned Long based on these 4 bytes
  byte Byte1 = EEPROM.read(EEPROM_address++);
  byte Byte2 = EEPROM.read(EEPROM_address++);
  byte Byte3 = EEPROM.read(EEPROM_address++);
  byte Byte4 = EEPROM.read(EEPROM_address++);
  #ifdef DEBUG_EEPROM
    // DEBUG mode on
    Serial.println("=== readUnsignedLongFromEEPROM ===");
    Serial.print("\tByte\t");   Serial.print("DEC"); Serial.print("\t"); Serial.println("HEX");
    Serial.print("\tByte1:\t"); Serial.print(Byte1); Serial.print("\t"); Serial.println(Byte1,HEX);
    Serial.print("\tByte2:\t"); Serial.print(Byte2); Serial.print("\t"); Serial.println(Byte2,HEX);
    Serial.print("\tByte3:\t"); Serial.print(Byte3); Serial.print("\t"); Serial.println(Byte3,HEX);
    Serial.print("\tByte4:\t"); Serial.print(Byte4); Serial.print("\t"); Serial.println(Byte4,HEX);
    Serial.print("\tUL value:\t"); Serial.println((unsigned long)( Byte1 + Byte2 * 256L + Byte3 * 65536L + Byte4 * 16777216L ));
    Serial.println("=== // readUnsignedLongFromEEPROM ===");
  #endif
  /*
    unsigned long retour;
    retour = b[3];
    retour += (b[2] * 256L);
    retour += (b[1] * 65536L);
    retour += (b[0] * 16777216L);
    return retour;
  */
  return (unsigned long) ( Byte1 + Byte2 * 256L + Byte3 * 65536L + Byte4 * 16777216L );
}


void writeUnsignedLongToEEPROM(unsigned int EEPROM_address, unsigned long value){
  // split Unisgned Long into 4 bytes
  // then check if these bytes are already in EEPROM in order to avoid EEPROM write cycles
  // if not, write them to EEPROM

  byte Byte1 = ((value >> 0)  & 0xFF);
  byte Byte2 = ((value >> 8)  & 0xFF);
  byte Byte3 = ((value >> 16) & 0xFF);
  byte Byte4 = ((value >> 24) & 0xFF);

  #ifdef DEBUG_EEPROM
    // DEBUG mode on
    Serial.println("=== writeUnsignedLongToEEPROM ===");
    Serial.print("\tByte1:\t"); Serial.print(Byte1); Serial.print("\t"); Serial.println(Byte1,HEX);
    Serial.print("\tByte2:\t"); Serial.print(Byte2); Serial.print("\t"); Serial.println(Byte2,HEX);
    Serial.print("\tByte3:\t"); Serial.print(Byte3); Serial.print("\t"); Serial.println(Byte3,HEX);
    Serial.print("\tByte4:\t"); Serial.print(Byte4); Serial.print("\t"); Serial.println(Byte4,HEX);
    Serial.print("\tUL value:\t"); 
    Serial.println((unsigned long)(Byte1+Byte2*256L+Byte3*65536L+Byte4*16777216L));
    Serial.println("=== // writeUnsignedLongToEEPROM ===");
  #endif
  
  if (Byte1 != EEPROM.read(EEPROM_address  )) { EEPROM.write(EEPROM_address  , Byte1); }
  if (Byte2 != EEPROM.read(EEPROM_address+1)) { EEPROM.write(EEPROM_address+1, Byte2); }
  if (Byte3 != EEPROM.read(EEPROM_address+2)) { EEPROM.write(EEPROM_address+2, Byte3); }
  if (Byte4 != EEPROM.read(EEPROM_address+3)) { EEPROM.write(EEPROM_address+3, Byte4); }
}

#endif
