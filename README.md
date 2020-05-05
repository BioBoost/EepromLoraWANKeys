# Eeprom LoraWAN Keys class

## How to use

1. mbed new .
2. mbed deploy
3. mbed add git@github.com:vives-projectwerk-2-2020/Driver_EEPROM.git
4. mbed toolchain GCC_ARM
5. mbed target detect
6. mbed compile -f

## code
```cpp 
#include "mbed.h"
#include "LoraKeys.h"
Serial pc(USBTX, USBRX);




int main()
{
    pc.printf("\r\n[Particula] Example of usage LoraKeys class");

    struct LoRaWAN::LoRaWANKeys lora_keys = {
        {0x10, 0x76, 0x92, 0x12, 0x52, 0x97, 0x99, 0xFF},                                                // devEui
        {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // appEui
        {0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} // appKey
    };

        

    LoRaWAN::Keys keys(lora_keys); //saving keys to eeprom

    char * devEui;
    char * appEui;
    char * appKey;

    pc.printf("\r\nReading devEui from eeprom");

    devEui = keys.read_devEui();
    
    
    pc.printf("\r\nReading appEui from eeprom");

    appEui = keys.read_appEui();

    pc.printf("\r\nReading appKey from eeprom");

    appKey = keys.read_appKey();
   
    pc.printf("\r\nPrinting devEui to serial\r\n");
    for(unsigned int i = 0; i < 8; i++){
        pc.printf("0x%x ", devEui[i]);
    }

    pc.printf("\r\nPrinting appEui to serial\r\n");
    for(unsigned int i = 0; i < 8; i++){
        pc.printf("0x%x ", appEui[i]);
    }

    pc.printf("\r\nPrinting appKey to serial\r\n");
    for(unsigned int i = 0; i < 16; i++){
        pc.printf("0x%x ", appKey[i]);
    }

    return 0;
}
```