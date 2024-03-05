#include <Arduino.h>
#define BUZZER_PIN 3

// put function declarations here:
// void setupGPS();
// void setupGSM();
// void setupAccel();
void checkAccident();
int AccidentTrack();

// void sendSMS(String message);
void setup()
{ pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (ِAccelometer_check_accident)
  {
  checkAccident();
  }
  
  
}


// put function definitions here:
void checkAccident()
{
    int button_state = digitalRead(8);
    if (button_state == LOW)
    {
      // Start countdown
      for (int i = 5; i > 0; i--)
      {
        // Turn on the alarm
        digitalWrite(7, HIGH);

        // Check if button is pressed during countdown
        if (digitalRead(8) == HIGH) {
          digitalWrite(7, LOW); // Stop the alarm
          return; // Exit the function
        }

        delay(1000); // Wait for 1 second
      }

     }
  
}