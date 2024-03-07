
#ifndef MAIN_CODE_H
#define MAIN_CODE_H

#include <SoftwareSerial.h>
#include <Arduino.h>
#define BUZZER_PIN 3
#define push_button 3
// Define the pins used to communicate with SIM900A and ESP8266
#define SIM900A_RX_PIN 2  // Connect SIM900A RX to Arduino pin 2
#define SIM900A_TX_PIN 3  // Connect SIM900A TX to Arduino pin 3
#define ESP8266_RX_PIN 4  // Connect ESP8266 RX to Arduino pin 4
#define ESP8266_TX_PIN 5  // Connect ESP8266 TX to Arduino pin 5

// Define the baud rates for SIM900A and ESP8266
#define SIM900A_BAUD_RATE 9600
#define ESP8266_BAUD_RATE 9600


SoftwareSerial sim900aSerial(SIM900A_RX_PIN, SIM900A_TX_PIN); // RX, TX
SoftwareSerial esp8266Serial(ESP8266_RX_PIN, ESP8266_TX_PIN); // RX, TX


void checkAccident();

#endif 