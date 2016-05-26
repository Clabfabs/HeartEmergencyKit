

HeartEmergencyKit
=================

This project has been developed for the [Cyber Physical System course](https://nettiopsu.utu.fi/opas/teaching/course.htm?id=9492) at the [University of Turku](www.utu.fi).

Introduction
------------
During the mentioned course, we were introduced to microcontroller boards like [Arduino Uno](https://www.arduino.cc/en/main/arduinoBoardUno), and were assigned the task of a practical project that needs to include some kind of wireless communication, preferably related to health care.  

Our group decided to create HeartBuddy, a Arduino Uno based device that monitors the heart rate of a person and triggers emergency messages via bluetooth on a connected Android phone. This means that the project consists of two parts:

* The device itself called HeartEmergencyKit (this repo)
* An Android application to handle the transmitted data: [Source](https://github.com/Clabfabs/HeartBuddy)

If the Android application is connected to the device, it will constantly receive & display the heart rate and emergency notifications, after which the Android phone sends a text message with the current heart rate and geolocation information to pre-defined care givers.   

Basis
-----
This code is based on the [example code](https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino) of the pulse sensor by [WorldFamousElectronics](https://github.com/WorldFamousElectronics), which brings most of the heart rate specific functionality.

Pre-requisites
--------------

- Arduino Uno board
- Sensors/Actuators: [Pulse sensor](http://pulsesensor.com/), [Bluetooth sensor](https://www.sparkfun.com/products/12577), Button, LED

Getting Started
---------------
Connect the sensors on the following pins:

- Pulse Sensor: Analog 0
- Bluetooth Sensor: Digital 10 (Tx), Digital 11 (Rx)
- Button: Digital 6
- LED: Digital 8

