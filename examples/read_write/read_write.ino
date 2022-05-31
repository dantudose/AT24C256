#define message_length 16
#include <AT24C256.h>
AT24C256 eeprom(0x50); // 0x50 is the I2C address of the EEPROM
uint16_t address = 0;
void setup() {
  Serial.begin(9600);
  Serial.print("Enter text to write: ");
}
void loop() {
  if(Serial.available() > 0){
  	char writemessage[message_length];
    char message[message_length];
    for(int j = 0; j < message_length; j++){
      writemessage[j] = 0;
      message[j] = 0;
    }
    Serial.readBytes(writemessage,message_length);
    Serial.print("\nwritemessage array: ");
    int end = message_length;
    for(int i = 0;i < message_length; i++){
      Serial.print(" ");
      Serial.print(writemessage[i],HEX);
      if((writemessage[i] == 10 || writemessage[i] == 13) && end == message_length) end = i;
    }
    if(end != 0){
      Serial.println();
      Serial.print("Address: ");
      Serial.println(address,DEC);
      Serial.print("Entered text: '");
      Serial.print(writemessage);
      Serial.println("'");
      eeprom.write(address,writemessage,end);
      Serial.print("Write complete, reading back: '");
      eeprom.read(address,message,end);
      Serial.print(message);
      Serial.println("'");
      address += end;
    }
    Serial.print("Enter text to write: ");
  }
}