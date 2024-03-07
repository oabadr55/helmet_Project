#include "MPU_Core.h"
 Adafruit_MPU6050 m_p_u;

void MPU_Set_Val()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    while (!Serial)
        delay(20);
    if (!m_p_u.begin())
    {
        while (1)
        {
            delay(20);
        }
    }
}

void MPU_Read_Val()
{
    sensors_event_t ACC, GCC, TEMP;
    m_p_u.getEvent(&ACC, &GCC, &TEMP);
    //  Serial.println("ACC on X Axis:");
    //  Serial.println(ACC.orientation.x);
    // delay(1500);
    // Serial.println("ACC on Y Axis:");
    // Serial.println(ACC.orientation.y);
    // delay(1500);
    // Serial.println("ACC on Z Axis:");
    // Serial.println(ACC.orientation.z);
    // delay(1500);

    // Serial.println("Rotation on X Axes:");
    // Serial.println((GCC.gyro.x) * 180 / 3.14); // because it measures in radiant
    // delay(1500);
    // Serial.println("Rotation on Y Axes:");
    // Serial.println((GCC.gyro.y) * 180 / 3.14); // because it measures in radiant
    // delay(1500);
    Serial.println("Rotation on Z Axes:");
    Serial.println((GCC.gyro.z) * 180 / 3.14); // because it measures in radiant
    // delay(1500);

    // Serial.println("Temp:");
    // Serial.println(TEMP.temperature);
    // delay(1500);
    if (((GCC.gyro.z) * 180 / 3.14) >= 0)
    {
        digitalWrite(LED_BUILTIN, LOW); // turn the LED on (HIGH is the voltage level)
        delay(1000);                // wait for a second
       
    }
     digitalWrite(LED_BUILTIN, HIGH);  // turn the LED off by making the voltage LOW
}