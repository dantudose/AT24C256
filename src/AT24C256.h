// 24C256 EEPROM driver header file
#ifndef AT24C256_h
#define AT24C256_h

#include "Arduino.h"
#include "Wire.h"

class AT24C256
{
public: 
		AT24C256(uint8_t address, TwoWire *twi);
		void begin(void);
		void write(uint16_t writeAddress, uint8_t* data, uint8_t len);
		void read(uint16_t readAddress, uint8_t* data, uint8_t len);

private:
		uint8_t _address;
		TwoWire *_twi;
};

#endif
