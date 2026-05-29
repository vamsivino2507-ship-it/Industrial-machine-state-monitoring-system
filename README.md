# Industrial Machine State Monitoring System

An IoT-based industrial monitoring system developed using ESP32 and multiple sensors to monitor machine and environmental conditions in real time. The system collects sensor data and uploads it to ThingSpeak Cloud for remote monitoring and analysis.

---

## Features

- Real-time industrial machine monitoring
- Wi-Fi connectivity using ESP32
- Cloud data logging using ThingSpeak
- Monitoring using multiple sensors
- Serial Monitor debugging output
- ESP32 Access Point support

---

## Components Used

| Component | Description |
|---|---|
| ESP32 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| DHT11 Sensor | Temperature and humidity monitoring |
| LDR Sensor | Light intensity detection |
| Potentiometer | Analog input monitoring |
| PIR Sensor | Motion detection |
| ThingSpeak | Cloud IoT platform |
| Breadboard & Jumper Wires | Circuit connections |

---

## Pin Configuration

| Sensor | ESP32 Pin |
|---|---|
| Ultrasonic Trigger | GPIO 27 |
| Ultrasonic Echo | GPIO 32 |
| Potentiometer | GPIO 36 |
| LDR | GPIO 39 |
| DHT11 | GPIO 14 |
| PIR Sensor | GPIO 25 |

---

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- Required Libraries:
  - WiFi.h
  - ThingSpeak.h
  - DHT.h

---

## Installation

### Step 1: Install Arduino IDE

Download Arduino IDE from:

https://www.arduino.cc/en/software

---

### Step 2: Install ESP32 Board Package

1. Open Arduino IDE
2. Go to:
   File → Preferences
3. Add the following URL in Additional Board Manager URLs:

```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

4. Go to:
   Tools → Board → Boards Manager
5. Search for ESP32
6. Install ESP32 package

---

### Step 3: Install Required Libraries

Go to:

Sketch → Include Library → Manage Libraries

Install:
- ThingSpeak
- DHT Sensor Library

---

## ThingSpeak Setup

1. Create an account:
   https://thingspeak.mathworks.com

2. Create a new channel

3. Create the following fields:

| Field | Sensor |
|---|---|
| Field 1 | Ultrasonic Sensor |
| Field 2 | Potentiometer |
| Field 3 | LDR |
| Field 4 | Temperature |
| Field 5 | Humidity |
| Field 6 | PIR Sensor |

4. Copy:
- Channel ID
- Write API Key

5. Replace these values in the code:

```cpp
#define CHANNEL_ID YOUR_CHANNEL_ID
#define API_KEY "YOUR_API_KEY"
```

---

## Wi-Fi Configuration

Update your Wi-Fi credentials in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

## Working Principle

1. ESP32 connects to Wi-Fi.
2. Sensors collect machine and environmental data.
3. Data is displayed on the Serial Monitor.
4. ESP32 uploads sensor readings to ThingSpeak cloud.
5. Users can monitor the system remotely using the ThingSpeak dashboard.

---

## Sensor Functions

### Ultrasonic Sensor
Measures distance or object position.

### Potentiometer
Simulates machine analog parameter monitoring.

### LDR Sensor
Detects surrounding light intensity.

### DHT11 Sensor
Measures:
- Temperature
- Humidity

### PIR Sensor
Detects human movement near the machine area.

---

## Sample Serial Output

```text
ultrasonic
25
uploaded successful

Potentio: 1450

LDR: 2200

Humidity: 60
Temperature: 30

PIR = 1
```

---

## Applications

- Industrial machine monitoring
- Smart factory systems
- Environment monitoring
- Remote equipment supervision
- Safety monitoring systems

---

## Future Improvements

- GSM alert system
- Mobile application integration
- Predictive maintenance using AI/ML
- OLED/LCD display support
- Database storage
- Relay-based machine control

---

## Project Structure

```text
Industrial-Machine-State-Monitoring-System/
│
├── Industrial_Monitoring.ino
├── README.md
└── images/
```

---

## Author

Vamsi  
