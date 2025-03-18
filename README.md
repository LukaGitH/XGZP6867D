# XGZP6867D Pressure Sensor - Arduino Example

This repository provides an **Arduino sketch** to interface with the **XGZP6867D** pressure sensor using the **I²C protocol**. It correctly reads **pressure (kPa)** and **temperature (°C)**, supporting both **positive and negative pressures**.

## 📌 Features
- Reads **pressure and temperature** from the sensor.
- Supports **negative pressure** using **two’s complement**.
- Configurable **K factor** for different sensor ranges.
- Works with **Arduino & ESP32** via **I²C**.

---

## 📡 Wiring Guide

| **Sensor Pin**  | **Arduino (5V Logic)** | **ESP32 (3.3V Logic)** | **PIN on Sensor Module** |
|---------------|----------------|----------------|----------------|
| **VDD (Power)** | `5V` | `3.3V` | **Pin 4** |
| **GND** | `GND` | `GND` | **Pin 3** |
| **SDA (Data)** | `A4 (SDA)` | `GPIO21 (SDA)` | **Pin 5** |
| **SCL (Clock)** | `A5 (SCL)` | `GPIO22 (SCL)` | **Pin 1** |

> 🛠 **Ensure pull-up resistors (4.7kΩ - 10kΩ) are used on SDA & SCL if not present on the module or Arduino board.**


---

## 🔧 Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/LukaGitH/XGZP6867D-Arduino.git
