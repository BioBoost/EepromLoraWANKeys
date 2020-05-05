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
        offset = 0;
        eeprom.write(devEui, length_of_devEui, offset);
        offset =+ length_of_devEui; //offset becomes 8
    }

    void Keys::write_appEui(char * appEui){
        eeprom.write(appEui, length_of_appEui, offset);
        offset =+length_of_appEui; //offset becomes 16
    }
    
    void Keys::write_appKey(char * appKey){
        eeprom.write(appKey, length_of_appKey, offset);
    }
 
    char * Keys::read_devEui(void){
        offset = 0; // offset needs to be 0 because it is written to offset 0
        eeprom.read(buffer_devEui, length_of_devEui, offset);
        return buffer_devEui;
    }
 

    char * Keys::read_appEui(void){
        offset = 8; // offset needs to be 8 because it is written to offset 8
        eeprom.read(buffer_appEui, length_of_appEui, offset);
        return buffer_appEui;
    }
            
    char * Keys::read_appKey(void){
        offset = 16; // // offset needs to be 16 because it is written to offset 16
        eeprom.read(buffer_appKey, length_of_appKey, offset);
        return buffer_appKey;
    }
}