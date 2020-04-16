#pragma once
#include "EEPROM.h"

struct LoRaWANKeys{
    char devEui[8];
    char appEui[8];
    char appKey[16];
};

namespace LoRaWAN{
    class Keys{
        public:
            Keys(struct LoraWANKeys);

        private:
            void set_devEui(char devEui[8]);
            void set_appEui(char appEui[8]);
            void set_appEui(char appKey[16]);

         public:
            void write_devEui(void);
            void write_appEui(void);
            void write_appKey(void);

        public:
            char read_devEui(void);
            char read_appEui(void);
            char read_appKey(void);

        public:
            int get_length_of_devEui(void);
            int get_length_of_appEui(void);
            int get_length_of_appKey(void);
        
        private:
            char devEui[8];
            char appEui[8];
            char appKey[16];

            char buffer_devEui[8]= {0};
            char buffer_appEui[8]= {0};
            char buffer_appKey[16]= {0};

        
            I2C i2cbus(D14, D15); //sda & scl
            EEPROMDriver::EEPROM eeprom(&i2cbus);

    };
};