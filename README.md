# Water Turbidity Sensor with Arduino Uno R3

This project demonstrates how to interface a Turbidity Sensor with an Arduino Uno R3 to monitor water quality using an I2C LCD display and LED indicators. The system detects whether the water is clean, cloudy, or dirty based on turbidity levels.

Hardware Components

Arduino Uno R3

Turbidity sensor module

16x2 I2C LCD Display

LEDs

Jumper wires

Breadboard

How It Works

The turbidity sensor continuously measures the clarity of water.

When clean water is detected, the green LED turns on and the LCD displays "Crystal Clear".

When cloudy water is detected, the yellow LED turns on and the LCD displays "Filter Needed".

When dirty water is detected, the red LED turns on and the LCD displays "Unsafe Water!".

Pin Connections

| Component | Arduino Pin |
|---|---|
| Turbidity Sensor AOUT | A0 |
| Green LED | 2 |
| Yellow LED | 3 |
| Red LED | 4 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Sensor VCC | 5V |
| Sensor GND | GND |

Circuit Diagram

![Water Turbidity Sensor Circuit Diagram](Turbidity-Sensor-Circuit-Diagram.png)

YouTube Demonstration

🔗 Watch the project in action on YouTube https://YOUR_YOUTUBE_LINK
