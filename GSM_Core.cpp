
#include "GSM_Core.h"
bool GSM_Start (int Phone_Number,String Message_content){

    
}


void setup() {
  // Begin serial communication with the PC
  Serial.begin(9600);
  // Begin serial communication with SIM900A
  sim900aSerial.begin(SIM900A_BAUD_RATE);
  // Begin serial communication with ESP8266
  esp8266Serial.begin(ESP8266_BAUD_RATE);

  delay(1000); // Allow time for the modules to initialize

  // Send AT command to SIM900A to check its status
  sendATCommand(&sim900aSerial, "AT");
  // Send AT command to ESP8266 to check its status
  sendATCommand(&esp8266Serial, "AT");
}

void loop() {
  // Check for incoming commands from the receiver
  if (esp8266Serial.available() > 0) {
    String command = esp8266Serial.readStringUntil('\n');
    if (command.indexOf("SEND_MESSAGE") != -1) {
      sendMessage(); // Call the function to send a message
    }
  }
}

void sendMessage() {
  // Send a message to the specified number
  sim900aSerial.println("AT+CMGF=1"); // Set SMS mode to text mode
  delay(1000);
  sim900aSerial.println("AT+CMGS=\"01017701300\""); // Replace 01017701300 with the desired phone number
  delay(1000);
  sim900aSerial.println("Hello, this is a test message!"); // Replace with the desired message
  delay(1000);
  sim900aSerial.println((char)26); // ASCII code for CTRL+Z
  delay(1000);
}

void sendATCommand(SoftwareSerial* serial, const char* command) {
  serial->println(command);
  delay(500);
  while (serial->available()) {
    Serial.write(serial->read());
  }
  Serial.println();
}