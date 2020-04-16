#include "LoraKeys.h"

namespace LoRaWAN{
     
    I2C i2cbus(D14, D15); //sda & scl
    EEPROMDriver::EEPROM eeprom(&i2cbus);

    void Keys::set_devEui(char devEui[8]){
        devEui = this->devEui;
    }
    
    void Keys::set_appEui(char appEui[8]){
        appEui = this->appEui;
    }
    
    void Keys::set_appKey(char appKey[8]){
        appKey = this->appKey;
    }

    void Keys::write_devEui(void){
        eeprom.write(devEui, get_length_of_devEui(), 0);
    }
    
    void Keys::write_appEui(void){
        eeprom.write(appEui, get_length_of_appEui(), get_length_of_devEui());
    }
    
    void Keys::write_appKey(void){
        eeprom.write(appKey, get_length_of_appkey(), get_length_of_devEui() + get_length_of_appEui());
    }

    int Keys::get_length_of_devEui(void){
        return sizeof(devEui);
    }

    int Keys::get_length_of_appEui(void){
        return sizeof(appEui);
    }

    int Keys::get_length_of_appKey(void){
        return sizeof(appKey);
    }

    char Keys::read_devEui(void){
        eeprom.read(buffer_devEui, get_length_of_devEui(), 0);
        return buffer_devEui;
    }
            
    char Keys::read_appEui(void){
        eeprom.read(buffer_appEui, get_length_of_appEui(), get_length_of_devEui());
        return buffer_appEui;
    }
            
    char Keys::read_appKey(void){
        eeprom.read(buffer_appKey, get_length_of_appKey(), get_length_of_devEui() + get_length_of_appEui());
        return buffer_appKey;
    }
}