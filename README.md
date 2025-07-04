
# Embedded-GPS

A lightweight embedded system project for interfacing with GPS modules, implementing data parsing and validation, finding the current location in real time and displaying the closest preset landmark to your coordinate on an LCD Display.

---

## ✨ Features

* **UART communication**: Interface with common GPS modules (e.g. NEO‑6M) via serial.
* **NMEA sentence parser**: Extracts key GPS data (`GPRMC`) – location, fix status.
* **Flexible output**: Easily adapt for:

  * LCD display
  * LEDs or buzzers

* **Modular structure**: Clear separation of:

  * Hardware drivers
  * Application layer

---

## 📁 Repository Structure

```
/
├── src/
│  ├── APP
│        └── main.c    # Application entry point
│  ├── HAL
│        ├── GPS.c     #NMEA sentence extraction, validation and landmark choosing
│        └── LCD.c     #LCD initialization driver
│  ├──  MCAL
│        ├── UART.c    #UART setup, read NMEA strings
│        ├── GPIO.c
│        └── TIMER.c  
│        
├── HEADERS/
│    ├── HAL/
│       ├── GPS.h
│       └── LCD.h
│   ├── MCAL/
│       ├── GPIO.h
│       ├── TIMER.h
│       └── UART.h
└── SERVICES/
│    ├── Bit_util.h
│    └── tm4c123gh6pm.h
│
└── README.md             # This documentation
```

---

## 🛠️ Getting Started

### Prerequisites

* Embedded toolchain (e.g. ARM GCC)
* GPS module (UART output, e.g. NEO‑6M)
* Microcontroller board (e.g. TIVA C)
* LCD Display

### Building

```bash
git clone https://github.com/AnasK239/Embedded-GPS.git
cd Embedded-GPS
```

### Hardware Connections

* **GPS TX → MCU RX** (UART)
* **GPS GND → MCU GND**
* **GPS VCC → 3.3 V / 5 V** (per GPS spec)

### Flash & Run

1. Flash binary to target MC using Keil 4.
2. Power on GPS; wait for satellite fix.
3. Monitor output via serial or on‑device display.

---

## 🧩 Code Breakdown

### `gps_uart`

Responsible for initializing UART and buffering incoming NMEA sentences.

### `nmea_parser`

* Validates Input
* Splits sentences into tokens
* Extracts:
  * Latitude / longitude
  * Fix quality



### `display`

Drives  LCD to show the current nearby location.

### `bit utils`

Helper bit manipulation definitions 

---

## 🔌 Extending the Project

* Add support for additional NMEA sentences (e.g. `GPGSA`, `GPVTG`, `GSV`)
* Log data to a server via Wi‑Fi or BLE
* Visualize data on-mcu with graphical gauges or maps
* Add error handling for UART disconnects, checksum failures

---

## 🧪 Testing & Debugging Tips
* Use USB-to-UART adapter to pipe NMEA data to a PC terminal
* Simulate NMEA sentences: run parser code on a desktop script




