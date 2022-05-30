#define message_length 5
#include <AT24C256.h>
AT24C256 eeprom(0x50); // 0x50 is the I2C address of the EEPROM
uint16_t address = 0;
void setup() {
  Serial.begin(9600);
  Serial.print("Enter address to read: ");
}
void loop() {
  if(Serial.available() > 0){
  	char writemessage[message_length];
    for(int j = 0; j < message_length; j++){
      writemessage[j] = 0;
    }
    Serial.readBytes(writemessage,message_length);
    Serial.print("\nwritemessage array: ");
    for(int i = 0;i < message_length; i++){
      Serial.print(" ");
      Serial.print(writemessage[i],HEX);
    }
    Serial.println();
    address = atoi(writemessage);
    Serial.print("Address: ");
    Serial.println(address,DEC);
    Serial.print("Reading: ");
    char message[1];
    eeprom.read(address,message,1);
    Serial.print(message);
    Serial.print("\nEnter address to read: ");
  }
}