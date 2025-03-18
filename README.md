# XGZP6867D Pressure Sensor - Arduino Example

This repository provides an **Arduino sketch** to interface with the **XGZP6867D** pressure sensor using the **I²C protocol**. It correctly reads **pressure (kPa)** and **temperature (°C)**, supporting both **positive and negative pressures**.

## 📊 Pressure Range Table

Below is the **pressure range (kPa) vs K value** table from the sensor datasheet:

![Pressure Range Table](pressure_range_table.png)

> **Note:** The `K` value is selected according to the **absolute pressure range**. Adjust it in the code accordingly.

## 📡 Wiring Guide

| **Sensor Pin**  | **Arduino (5V Logic)** | **ESP32 (3.3V Logic)** | **PIN on Sensor Module** |
|---------------|----------------|----------------|----------------|
| **VDD (Power)** | `5V` | `3.3V` | **Pin 4** |
| **GND** | `GND` | `GND` | **Pin 3** |
| **SDA (Data)** | `A4 (SDA)` | `GPIO21 (SDA)` | **Pin 5** |
| **SCL (Clock)** | `A5 (SCL)` | `GPIO22 (SCL)` | **Pin 1** |

> 🛠 **Ensure pull-up resistors (4.7kΩ - 10kΩ) are used on SDA & SCL if not present on the module or Arduino board.**
