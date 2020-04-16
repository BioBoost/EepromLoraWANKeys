#include "mbed."
#include "EEPROM.h"

using namespace EEPROMDriver;

Serial pc(USBTX, USBRX);

int main()
{

    printf("\r\n[Particula] Example of using EEPROM driver");

    struct LoRaWANKeys
    {
        char devEui[8];
        char appEui[8];
        char appKey[16];
    };

    LoRaWANKeys keys = {
        {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // devEui
        {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // appEui
        {0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} // appKey
    };

    unsigned int length_devEui = sizeof(keys.devEui);
    unsigned int length_appEui = sizeof(keys.appEui);
    unsigned int length_appKey = sizeof(keys.appKey);

    char buffer_devEui[length_devEui] = {0};
    char buffer_appEui[length_appEui] = {0};
    char buffer_appKey[length_appKey] = {0};

    I2C i2cbus(D14, D15); //sda & scl
    EEPROMDriver::EEPROM eeprom(&i2cbus);

    pc.printf("\r\nWriting devEui to eeprom");

    eeprom.write(keys.devEui, length_devEui, 0);

    pc.printf("\r\nWriting appEui to eeprom");

    eeprom.write(keys.appEui, length_appEui, length_devEui);

    pc.printf("\r\nWriting appKey to eeprom");

    eeprom.write(keys.appKey, length_appKey, length_devEui + length_appEui);

    //devEui
    pc.printf("\r\nReading devEui from eeprom");
    pc.printf("\r\n");

    eeprom.read(buffer_devEui, length_devEui, 0);

    for (unsigned int i = 0; i < length_devEui; i++)
    {
        pc.printf("0x%x ", buffer_devEui[i]);
    }

    //appEui
    pc.printf("\r\nReading appEui from eeprom");
    pc.printf("\r\n");

    eeprom.read(buffer_appEui, length_appEui, length_devEui);

    for (unsigned int i = 0; i < length_appEui; i++)
    {
        pc.printf("0x%x ", buffer_appEui[i]);
    }

    //appkey
    pc.printf("\r\nReading appKey from eeprom");
    pc.printf("\r\n");

    eeprom.read(buffer_appKey, length_appKey, length_devEui + length_appEui);

    for (unsigned int i = 0; i < length_appKey; i++)
    {
        pc.printf("0x%x ", buffer_appKey[i]);
    }

    while (1)
    {
        ThisThread::sleep_for(30000);
    }

    return 0;
}