#include <Wire.h>

#define SENSOR_ADDR 0x6D  // Sensor I2C address

// Set K factor based on your pressure range (from the datasheet table)
#define K_VALUE 64  // Example: For -100~100 kPa range

void writeByte(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(SENSOR_ADDR);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t readByte(uint8_t reg) {
    Wire.beginTransmission(SENSOR_ADDR);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(SENSOR_ADDR, 1);
    if (Wire.available()) {
        return Wire.read();
    }
    return 0;
}

void setup() {
    Serial.begin(115200);
    Wire.begin();
}

void loop() {
    // Start measurement
    writeByte(0x30, 0x0A);

    // Wait for conversion to complete
    while (readByte(0x30) & 0x08) {
        delay(1);
    }

    // Read 24-bit pressure ADC value
    int32_t pressure_adc = (int32_t)readByte(0x06) << 16;
    pressure_adc |= (int32_t)readByte(0x07) << 8;
    pressure_adc |= readByte(0x08);

    // Check if the value is negative (two's complement 24-bit)
    if (pressure_adc & 0x800000) {  // If highest bit is 1, it’s negative
        pressure_adc = pressure_adc - 16777216;
    }

    // Convert pressure using the correct K factor
    float pressure = (float)pressure_adc / K_VALUE;

    // Convert pressure to kPa (Pa to kPa)
    pressure /= 1000.0;

    // Read 16-bit temperature ADC value
    int16_t temperature_adc = (int16_t)readByte(0x09) << 8;
    temperature_adc |= readByte(0x0A);

    // Convert temperature (two's complement 16-bit)
    if (temperature_adc & 0x8000) {  // If highest bit is 1, it’s negative
        temperature_adc = temperature_adc - 65536;
    }
    float temperature = temperature_adc / 256.0;

    // Print values
    Serial.print("Pressure: ");
    Serial.print(pressure, 2);
    Serial.print(" kPa");

    Serial.print("   Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" °C");

    delay(100);
}
