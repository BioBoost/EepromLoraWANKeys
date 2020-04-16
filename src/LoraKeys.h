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
            void set_devEui(char* devEui);
            void set_appEui(char* appEui);
            void set_appKey(char* appKey);

         public:
            void write_devEui(void);
            void write_appEui(void);
            void write_appKey(void);

        public:
            void read_devEui(void);
            void read_appEui(void);
            void read_appKey(void);

        public:
            char* get_devEui(void);
            char* get_appEui(void);
            char* get_appKey(void);

        public:
            int get_length_of_devEui(void);
            int get_length_of_appEui(void);
            int get_length_of_appKey(void);
        
        public:
            void print_devEui_Serial(void);

        private:
            // char devEui[8]={0};
            char * devEui;
            char appEui[8]={0};
            char appKey[16]={0};

            char buffer_devEui[8]={0};
            char buffer_appEui[8]={0};
            char buffer_appKey[16]={0};

            
            

    };
};