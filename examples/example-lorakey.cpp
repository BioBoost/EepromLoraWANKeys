#include "mbed.h"
#include "LoraKeys.h"

Serial pc(USBTX, USBRX);

int main()
{
    pc.printf("\r\n[Particula] Example of usage LoraKeys class");

    struct LoRaWAN::LoRaWANKeys lora_keys = {
        {0x10, 0x76, 0x92, 0x12, 0x52, 0x97, 0x99, 0xFF},                                                // example of devEui
        {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // example of appEui
        {0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} // example of appKey
    };

    LoRaWAN::Keys keys(lora_keys); //when maken object of the class the keys are automaticly saved to the eeprom
    
    char * devEui; // variable to store the read keys
    char * appEui;
    char * appKey;

    unsigned int lengthOfdevEui = 8; // hardcoded lengths of the keys because they never never change
    unsigned int lengthOfappEui = 8;
    unsigned int lengthOfappKey = 16;

    pc.printf("\r\nReading devEui from eeprom");
    devEui = keys.read_devEui();
    
    pc.printf("\r\nReading appEui from eeprom");
    appEui = keys.read_appEui();

    pc.printf("\r\nReading appKey from eeprom");
    appKey = keys.read_appKey();
   
    pc.printf("\r\nPrinting devEui to serial\r\n");
    for(unsigned int i = 0; i < lengthOfdevEui; i++){
        pc.printf("0x%x ", devEui[i]);
    }

    pc.printf("\r\nPrinting appEui to serial\r\n");
    for(unsigned int i = 0; i < lengthOfappEui; i++){
        pc.printf("0x%x ", appEui[i]);
    }

    pc.printf("\r\nPrinting appKey to serial\r\n");
    for(unsigned int i = 0; i < lengthOfappKey; i++){
        pc.printf("0x%x ", appKey[i]);
    }

    return 0;
}