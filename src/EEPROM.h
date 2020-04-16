#pragma once
#include "mbed.h"

namespace EEPROMDriver{
    class EEPROM{
        
        public:
            EEPROM(I2C * i2cBus);       // Here you have to give a pointer for the I2C object that is used for interfacing with the eeprom
            void read(char buffer[], unsigned int length, unsigned int offset);
            void write(char buffer[], unsigned int length, unsigned int offset);
        

        private:
            const char i2cAddress = 0x50 << 1;    // The only avalible I2C Address for our eeprom
            I2C * i2cBus;
    };
};