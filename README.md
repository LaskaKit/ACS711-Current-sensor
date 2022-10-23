# ACS711 Current sensor module


![ACS711 current sensor](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/ACS711_monitor.jpg)

Do you need to measure a flowing current through your load? So let's check out module with ACS711 current sensor in x31AB version, what is able to measure up to 31A.
The biggest advantage of this sensor is easy output with conversion ratio 45mV/A, so you may measure the current by general AD convertor in Arduino Uno or ESP32. The next advatage is the hall sensor inside of chip. Thanks to this hall sensor, you don't need a shunt resistor where you measure voltage drop on resistor. Thanks to this, you don't have a voltage drop on your power line. Moreover you don't need to dissipate heat from the component.

## ACS711-31AB
The output voltage without flowing current is around 1.7V (power supply 3.3V). It means, you may measure the current in both polarity. The output voltage (VIOUT) je higher or lower depending on the measured polarity. 
The conversation ratio for version 31AB is 45mV/1A. It means in case you measure 1A, the difference of VIOUT voltage is 45 mV. 
The output of sensor is noisy, the datasheet defined the noise as 8 mV (it means almost 20% from conversation ratio). Our module includes capacitor which helps to reduce the noise on the output (VIOUT). 
The power supply voltage is from 3 to 5.5V, so you can use the Arduino Uno, Mega or evaluation board with ESP8266 or ESP32.

The connection of load may by done by screw connector or by screws. This connection has a big impact on the input voltage, so be careful. 

## Connection
There is 4th pin male header where you find power supply (3-5.5V), output from sensor (VIOUT) and also alarm output which indicates the overcurrent.

## Example
We prepared an [example on github](https://github.com/LaskaKit/ACS711-Current-sensor/tree/main/SW) how to use this module with our [ESP32 LPkit](https://www.laskarduino.cz/laskakit-esp32-lpkit-pcb-antenna/) evaluation board.
At first, we will measure the value without load. It is our base when we will subtract or add the voltage based on the polarity of measured current. 

![Output of ACS711 in Arduino IDE](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/ACS711_plotter.JPG)

The measured values is averaged. Thanks to the averaging of output voltage, we eliminate the noise from sensor and also from AD convertor. The precicision is much better. 

![TOP of ACS711](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/3.jpg)

![BOTTOM of  ACS711](https://github.com/LaskaKit/ACS711-Current-sensor/blob/main/img/5.jpg)
