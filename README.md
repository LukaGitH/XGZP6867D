# XGZP6867D Pressure Sensor - Arduino Example

This repository provides an **Arduino sketch** to interface with the **XGZP6867D** pressure sensor using the **I²C protocol**. It correctly reads **pressure (kPa)** and **temperature (°C)**, supporting both **positive and negative pressures**.

## 📌 Features
- Reads **pressure and temperature** from the sensor.
- Supports **negative pressure** using **two’s complement**.
- Configurable **K factor** for different sensor ranges.
- Works with **Arduino & ESP32** via **I²C**.

---

## 📡 Wiring Guide

| **Sensor Pin** | **Arduino (5V Logic)** | **ESP32 (3.3V Logic)** | PIN on sensor module
|--------------|----------------|----------------|
| **VDD** (Power) | `5V` | `3.3V` | PIN4 on sensor
| **GND** | `GND` | `GND` | PIN3 on sensor
| **SDA** (Data) | `A4 (SDA)` | `GPIO21 (SDA)` | PIN5 on sensor
| **SCL** (Clock) | `A5 (SCL)` | `GPIO22 (SCL)` | PIN1 on sensor

> 🛠️ **Ensure pull-up resistors (4.7kΩ - 10kΩ) are used on SDA & SCL if not present on the module or Arduino board.**

---

## 🔧 Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/YOUR_USERNAME/XGZP6867D-Arduino.git
