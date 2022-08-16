//AT24C256 driver CPP file
#include "Arduino.h"
#include "Wire.h"
#include "AT24C256.h"

AT24C256::AT24C256(int address){
	Wire.begin();
	_address = address;
}

void AT24C256::write(uint16_t writeAddress, uint8_t* data, uint16_t len){

	Wire.beginTransmission(_address);
	Wire.write((byte)(writeAddress & 0xFF00) >> 8);
	Wire.write((byte)(writeAddress & 0x00FF));
	uint8_t i;
	for(i = 0; i < len; i++){
		Wire.write(data[i]);
	}
	Wire.endTransmission();

}

void AT24C256::read(uint16_t readAddress, uint8_t* data, uint16_t len){

	Wire.beginTransmission(_address);
	Wire.write((byte)(readAddress & 0xFF00) >> 8);
	Wire.write((byte)(readAddress & 0x00FF));
	Wire.endTransmission();

	Wire.requestFrom(_address, len);
	int i;
	for(i = 0; i < len; i++){
		if(Wire.available()) data[i] = Wire.read();
	}

}
