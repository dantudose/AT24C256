//AT24C256 driver CPP file
#include "Arduino.h"
#include "Wire.h"
#include "AT24C256.h"

AT24C256::AT24C256(uint8_t address){
	Wire.begin();
	_address = address;
}

void AT24C256::write(uint16_t writeAddress, uint8_t* data, uint8_t len){
	byte thisLen;
	while(len > 0){
		if(len > 16){
			thisLen = 16;
			len -= thisLen;
		}
		else{
			thisLen = len;
			len = 0;
		}
		Wire.beginTransmission((int)_address);
		//Wire.write((int)((writeAddress & 0xFF00) >> 8));
		//Wire.write((int)(writeAddress & 0x00FF));
		Wire.write((int)(writeAddress >> 8));
		Wire.write((int)(writeAddress & 0xFF));
		for(int i = 0; i < thisLen; i++) Wire.write(data[i]);
		Wire.endTransmission();
		writeAddress += thisLen;
		delay(6);
	}
}

void AT24C256::read(uint16_t readAddress, uint8_t* data, uint8_t len){
	Wire.beginTransmission((int)_address);
	Wire.write((int)(readAddress >> 8));
	Wire.write((int)(readAddress & 0xFF));
	Wire.endTransmission();
	Wire.requestFrom((int)_address, (int)len);
	for(int i = 0; i < len; i++)
		if(Wire.available())
			data[i] = Wire.read();
		else
			break;
}