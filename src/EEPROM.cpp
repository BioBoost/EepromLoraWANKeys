#include "mbed.h"
#include "EEPROM.h"

namespace EEPROMDriver{

    EEPROM::EEPROM(I2C * i2cBus){
        this->i2cBus = i2cBus;
    }

    void EEPROM::read(char buffer[], unsigned int length, unsigned int offset){

        char data[2];
        data[0] = (offset >> 8) & 0xFF;
        data[1] = offset & 0xFF;

        i2cBus->write(i2cAddress, data, 2);
        i2cBus->read(i2cAddress, buffer, length);
    }

    void EEPROM::write(char buffer[], unsigned int length, unsigned int offset){

        char data[length+2];
        data[0] = (offset >> 8) & 0xFF;
        data[1] = offset & 0xFF;

        for(unsigned int i = 0; i<length; i++){
            data[i+2] = buffer[i];
        }

        i2cBus->write(i2cAddress, data, length+2);
        wait_ms(10); //write cycle delay
    }
    
};