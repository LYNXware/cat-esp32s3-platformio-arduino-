#ifndef ESP_NOW_H
#define ESP_NOW_H
#include "config.h"

#include <Arduino.h>


#include <WiFi.h>
#include <esp_now.h>


class EspNow {

    public:

        void initialize();


        void test();

        void send_switch_layer(uint8_t dynamicValue);

        static uint8_t testValue;

        void scan_for_slave();


    private:

        // wifi network name
        const char *SSID = "cat_slave";
        #define CHANNEL 1

        // void scan_for_slave();

        uint8_t mac[6];

        // master_mac[6]
        // slave_mac[6]



        esp_now_peer_info_t peerInfo;
    
        static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);

        static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 




};

//instance of the class 
extern EspNow espnow;

#endif