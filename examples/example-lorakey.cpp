#include "mbed.h"
#include "LoraKeys.h"

Serial pc(USBTX, USBRX);

int main()
{
    printf("\r\n[Particula] Example of usage LoraKeys class");

    LoRaWANKeys lora_keys = {
        {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // devEui
        {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // appEui
        {0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} // appKey
    };

    LoRaWAN::Keys keys(lora_keys); //saving keys to eeprom

    char * devEui;
    char * appEui;
    char * appKey;

    pc.printf("\r\nReading devEui to eeprom");

    devEui = keys.read_devEui();
    
    pc.printf("\r\nReading appEui to eeprom");

    appEui = keys.read_appEui();

    pc.printf("\r\nReading appKey to eeprom");

    appKey = keys.read_appKey();
   
    pc.printf("\r\nPrinting devEui to serial\r\n");
    for(unsigned int i = 0; i < sizeof(devEui); i++){
        pc.printf("0x%x ", devEui[i]);
    }

    pc.printf("\r\nPrinting appEui to serial\r\n");
    for(unsigned int i = 0; i < sizeof(appEui); i++){
        pc.printf("0x%x ", appEui[i]);
    }

    pc.printf("\r\nPrinting appKey to serial\r\n");
    for(unsigned int i = 0; i < sizeof(appKey); i++){
        pc.printf("0x%x ", appKey[i]);
    }
}