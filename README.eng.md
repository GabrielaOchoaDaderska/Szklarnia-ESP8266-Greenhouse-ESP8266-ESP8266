# Project of the ESP8266 greenhouse with a website created by Wi-Fi. 

*Read this in other languages: [Polish](README.md), [English]( README.eng.md)*

## Table of Contents
- [Description of idea/goal](#Description-idea/goal)
- [Operation schemes](#Operation-schemes)
- [Description of operation](#Description-of-operation)
- [Greenhouse](#Greenhouse)
- [Evaluation](#Evaluation)
      
## Description of idea/goal
*COMPONENTS*

The project will be created using modules. The following will be used for this purpose:
- ESP8266 WiFi MODULE,
- Arduino Uno
- Temperature and humidity sensor - DHT11,
- Module soil moisture sensor,
- Battery basket 2XAA, 3xAA, 4xAA.
- LD3007MS fan,
- Mini water pump with USB DC 5V 2-3L/Min cable,
- Water level sensor
- Battery basket 3XAA R6,
- Robogeek S0022 water detector module,
- Vibration sensor
- LED.

*DESCRIPTION*
> The project had an ESP8266 WIFI module to control the components, a temperature and humidity sensor to measure the temperature and humidity levels in the greenhouse, a vibration sensor in the event of a mechanical shift of the mobile greenhouse, it is connected to the Arduino Uno and placed separately at the bottom of the greenhouse. Arduino Uno is connected to the 3xAA battery basket. The shift is signaled by the diode lighting up. Soil moisture module for soil water testing needed for soil hydration monitoring. All electronics will be powered by a 2xAA battery basket. The design includes a water pump for irrigation and a fan connected to a separate basket of 4xAA batteries. The rain level sensor is located at the top of the greenhouse above the water tank. A water level sensor is also placed in the container. In order to read the data from the sensors, turn on the pump and the fan, a website has been written.

---

## Operation schemes

![obraz](https://user-images.githubusercontent.com/108947060/209952018-98f2194f-009c-4f7c-85f8-09e81af9380c.png)

![obraz](https://user-images.githubusercontent.com/108947060/209952053-f9221b98-d4b9-46f2-b5ae-0a0130e04454.png)

---

## Description of operation

> The greenhouse has sensors that are programmed and read by the ESP8266. A website has been created showing: temperature in *C and air humidity in % (DHT11), soil moisture in % (LM393), water level in the rainwater tank (Water level sensor), rain sensor showing information whether it is raining or not (Rain sensor ), a pump and a fan activated by a button on the page. Separately, an arduino vibration sensor was created at the bottom of the greenhouse.
---

## Greenhouse

![obraz](https://user-images.githubusercontent.com/108947060/210071608-bc39d351-854c-4633-abcf-f8defaaafe66.png)

![obraz](https://user-images.githubusercontent.com/108947060/210071632-a6f2724f-091c-4630-ae31-5b9521b8ef21.png)

---

## Evaluation
1. The theme of the project was to create a greenhouse monitored using ESP8266 and auxiliary sensors.
2. The greenhouse was created using all the sensors from the project description including the windmill and the auxiliary pump for plant care.
3. 95% of the assumed goals of the greenhouse were achieved, including the creation of the possibility of reading data from sensors via Wi-Fi
4. The greenhouse power supply has been changed from the previous assumptions to 3 battery baskets, one separate for the pump and fan, one for the ESP8266 and one for the Arduino Uno.
5. The greenhouse meets the condition of portability, it is possible to change its location without any problems (with error tolerance).
6. The greenhouse has passed 3 short-circuit use tests to avoid the sensors from being burnt due to the load.

---
!!! CODE DOES NOT INCLUDE LIBRARIES AND ASSIGN TO PINS !!!
