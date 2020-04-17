#include "LoraKeys.h"

namespace LoRaWAN{
     
    I2C i2cbus(D14, D15); //sda & scl
    EEPROMDriver::EEPROM eeprom(&i2cbus);

    Keys::Keys(LoRaWANKeys lora_keys){
        write_devEui(lora_keys.devEui);
        write_appEui(lora_keys.appEui);
        write_appKey(lora_keys.appKey);
    }

    void Keys::write_devEui(char * devEui){
        eeprom.write(devEui, 8,0);
    }
    
    void Keys::write_appEui(char * appEui){
        eeprom.write(appEui, 8,8);
    }
    
    void Keys::write_appKey(char * appKey){
        eeprom.write(appKey, 16, 16);
    }

    char * Keys::read_devEui(void){
        eeprom.read(buffer_devEui, 8, 0);   
        return buffer_devEui;
    }
            
    char * Keys::read_appEui(void){
        eeprom.read(buffer_appEui, 8, 8);
        return buffer_appEui;
    }
            
    char * Keys::read_appKey(void){
        eeprom.read(buffer_appKey, 16, 16);
        return buffer_appKey;
    }

    int Keys::get_Length_Of_Key(char * key){
        return sizeof(key);
    }
}