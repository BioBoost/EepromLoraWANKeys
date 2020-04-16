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
            void write_devEui(char* devEui);
            void write_appEui(char* appEui);
            void write_appKey(char* appKey);

        public:
            char * read_devEui(void);
            char * read_appEui(void);
            char * read_appKey(void);

        private:
            char * buffer_devEui;
            char * buffer_appEui;
            char * buffer_appKey; 

    };
};