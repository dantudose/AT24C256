//AT24C256 driver CPP file
#include "Arduino.h"
#include "Wire.h"
#include "AT24C256.h"

AT24C256::AT24C256(int address, TwoWire *twi){
	
	_twi = twi;
	_address = address;

}

void AT24C256::begin(void){

	_twi->begin();

}

void AT24C256::write(uint16_t writeAddress, uint8_t* data, uint8_t len){

	_twi->beginTransmission(_address);
	_twi->write((byte)((writeAddress & 0xFF00) >> 8));
	_twi->write((byte)(writeAddress & 0x00FF));
	uint8_t i;
	for(i = 0; i < len; i++){
		_twi->write(data[i]);
	}
	_twi->endTransmission();

}

void AT24C256::read(uint16_t readAddress, uint8_t* data, uint8_t len){

	_twi->beginTransmission(_address);
	_twi->write((byte)((readAddress & 0xFF00) >> 8));
	_twi->write((byte)(readAddress & 0x00FF));
	_twi->endTransmission();

	_twi->requestFrom(_address, len);
	int i;
	for(i = 0; i < len; i++){
		if(_twi->available()) data[i] = _twi->read();
	}

}
