#pragma once
#include "EEPROM.h"

namespace LoRaWAN{

    struct LoRaWANKeys{
    char devEui[8];
    char appEui[8];
    char appKey[16];
    };

    class Keys{
        public:
           Keys(struct LoRaWANKeys);

        public:
            void write_devEui(char* devEui);
            void write_appEui(char* appEui);
            void write_appKey(char* appKey);

        public:
            char * read_devEui(void);
            char * read_appEui(void);
            char * read_appKey(void);

        private:
            unsigned int length_of_devEui = 8;
            unsigned int length_of_appEui = 8;
            unsigned int length_of_appKey = 16;
            unsigned int offset = 0;
            
        private:
            char buffer_devEui[8]={0};
            char buffer_appEui[8]={0};
            char buffer_appKey[16]={0}; 

    };
};