#include "LoraKeys.h"

namespace LoRaWAN{
    
    Keys::Keys(LoRaWANKeys){
        set_devEui(LoraWANKeys.devEui);
        set_appEui(LoRaWANKeys.appEui);
        set_appKey(LoRaWANKeys.appKey);
    }

    void Keys::set_devEui(char devEui[8]){
        this->devEui = devEui;
    }
    
    void Keys::set_appEui(char appEui[8]){
        this->appEui = appEui;
    }
    
    void Keys::set_appKey(char appKey[16]){
        this->appKey = appKey;
    }

    void Keys::write_devEui(void){
        eeprom.write(devEui, get_length_of_devEui, 0);
    }
    
    void Keys::write_appEui(void){
        eeprom.write(appEui, get_length_of_appEui, get_length_of_devEui);
    }
    
    void Keys::write_appKey(void){
        eeprom.write(appKey, get_length_of_appkey, get_length_of_devEui + get_appEui);
    }

    int get_length_of_devEui(void){
        return sizeof(devEui);
    }

    int get_length_of_appEui(void){
        return sizeof(appEui);
    }

    int get_length_of_appKey(void){
        return sizeof(appKey);
    }

    char read_devEui(void){
        eeprom.read(buffer_devEui, get_length_of_devEui, 0);
        return buffer_devEui;
    }
            
    char read_appEui(void){
        eeprom.read(buffer_appEui, get_length_of_appEui, get_length_of_devEui);
        return buffer_appEui;
    }
            
    char read_appKey(void){
        eeprom.read(buffer_appKey, get_length_of_appKey, get_length_of_devEui + get_appEui);
        return buffer_appKey;
    }
}