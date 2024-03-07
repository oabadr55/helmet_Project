
// put function declarations here:
// void setupGPS();
// void setupGSM();
// void setupAccel();
#include <main_code.h>
#include "MPU_Core.h"
#include "GSM_Core.h"



// void sendSMS(String message);
void setup()
{

  MPU_Set_Val();
  //pinMode(BUZZER_PIN, OUTPUT);
  //pinMode(8, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (1) // koreyem part  added here
  {
    MPU_Read_Val();
   checkAccident();
   GSM_Start ("01092255419","accident happend");
  }
}

// put function definitions here:
