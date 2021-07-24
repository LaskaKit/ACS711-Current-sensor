/*
* Example code of current sensor ACS711 with ESP32 LPkit
* The ADC output of ACS711 (VIOUT) is connected to GPIO34 of ESP32 LPkit
* 
* Made by laskarduino (c) 2021
* Libraries
* -
*
*/

#include "esp_adc_cal.h"

// VIOUT of ACS711 to GPIO 34 (Analog ADC1_CH6) 
const int ADCpin = 34;

// Variable for storing the values
double voltage = 0;
double voltageRef = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Reference voltage without load
  voltageRef = avgVal(ADCpin, 50, 5);

}

void loop() {
  // Reading VIOUT value
  voltage = avgVal(ADCpin, 50, 1);

  Serial.print("Voltage: "); Serial.print((int)voltage); Serial.println(" mV");
  Serial.print("Current: "); Serial.print(((voltage - voltageRef)/45)); Serial.println(" A");
  //Serial.println(((voltage - voltageRef)/45)); // used for plotter in Arduino
  delay(1000);
}

// Averaging function for reading values to eliminate the ADC noise of ESP32
double avgVal(int pin, int filterLen, int delayMs)
{
  int value = 0;
  double voltage; 

  for(int filterLen=0; filterLen < 50; filterLen++)
  {
    value += analogRead(pin);
    delay(delayMs);
  }
  voltage= readADC_Cal(value/filterLen);
  return voltage;
}

// ADC calibration and convert to adopted value
uint32_t readADC_Cal(int ADC_Raw)
{
  esp_adc_cal_characteristics_t adc_chars;
  esp_adc_cal_value_t val_type = esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
  return(esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars));
}
