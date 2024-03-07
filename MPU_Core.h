#ifndef MPU_CORE_H
#define MPU_CORE_H
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>


extern Adafruit_MPU6050 m_p_u;
int const LedPin = 5 ;


void MPU_Set_Val();
void MPU_Read_Val();
bool GSM_Start (int Phone_Number,String Message_content);
#endif