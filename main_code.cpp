#include <main_code.h>



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
      delay(900);
      digitalWrite(7, LOW);
      delay(500);
      digitalWrite(7, HIGH);
      delay(900);
      digitalWrite(7, LOW);
      delay(500);
      digitalWrite(7, HIGH);
      delay(900);
      digitalWrite(7, LOW);
      digitalWrite(7, HIGH);
      delay(500);
      digitalWrite(7, LOW);
      delay(900);

      // Check if button is pressed during countdown
      if (digitalRead(8) == HIGH)
      {
        digitalWrite(7, LOW); // Stop the alarm
        return;               // Exit the function
      }

      delay(1000); // Wait for 1 second
    }
  }
}