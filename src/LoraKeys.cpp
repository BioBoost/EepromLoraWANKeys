#include "LoraKeys.h"

namespace LoRaWAN{
     
    I2C i2cbus(D14, D15); //sda & scl
    EEPROMDriver::EEPROM eeprom(&i2cbus);

    Serial pc(USBTX, USBRX);

    void Keys::set_devEui(char* devEui){
            this->devEui = devEui;
    }
    
    void Keys::set_appEui(char* appEui){
        for(int i = 0; i<8 ;i++){
            this->appEui[i] = appEui[i];
        }
        
    }
    
    void Keys::set_appKey(char* appKey){
         for(int i = 0; i<16 ;i++){
            this->appKey[i] = appKey[i];
        }
        
    }

    void Keys::write_devEui(void){
        eeprom.write(devEui, get_length_of_devEui(), 0);
    }
    
    void Keys::write_appEui(void){
        eeprom.write(appEui, get_length_of_appEui(), get_length_of_devEui());
    }
    
    void Keys::write_appKey(void){
        eeprom.write(appKey, get_length_of_appKey(), get_length_of_devEui() + get_length_of_appEui());
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

    void Keys::read_devEui(void){
        eeprom.read(buffer_devEui, get_length_of_devEui(), 0);
        
    }
            
    void Keys::read_appEui(void){
        eeprom.read(buffer_appEui, get_length_of_appEui(), get_length_of_devEui());
       
    }
            
    void Keys::read_appKey(void){
        eeprom.read(buffer_appKey, get_length_of_appKey(), get_length_of_devEui() + get_length_of_appEui());
       
    }

    char* Keys::get_devEui(void){
        // for(int i = 0; i < get_length_of_devEui(); i++){

        //     buffer_devEuiCast[i] = buffer_devEui[i];
            
        // } 
        return buffer_devEui;
    }

    char* Keys::get_appEui(void){
        return buffer_appEui;
    }

    char* Keys::get_appKey(void){
        return buffer_appKey;
    }


    void Keys::print_devEui_Serial(void){
        for(int i = 0; i < get_length_of_devEui(); i++){
            pc.printf("0x%x ", buffer_devEui[i]);
        }
    }
}