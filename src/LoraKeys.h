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
            int get_Length_Of_Key(char * key);
            
        private:
            char buffer_devEui[8]={0};
            char buffer_appEui[8]={0};
            char buffer_appKey[16]={0}; 
            


    };
};