#pragma once
#include <Arduino.h>

namespace BMEConstants {
    const uint8_t I2C_ADDRESS = 0x76; // I2C address of the BME280 sensor
    const uint8_t BME280_CHIP_ID = 0x60; // Chip ID for the BME280 sensor
    const uint8_t BME280_RESET_VALUE = 0xB6; // Reset value for the BME280 sensor
    const uint8_t BME280_CTRL_HUM = 0xF2; // Control register for humidity
    const uint8_t BME280_CTRL_MEAS = 0xF4; // Control register for measurement
    const uint8_t BME280_CONFIG = 0xF5; // Configuration register
    const uint8_t BME280_PRESSURE_MSB = 0xF7; // Pressure MSB register
    const uint8_t BME280_PRESSURE_LSB = 0xF8; // Pressure LSB register
    const uint8_t BME280_PRESSURE_XLSB = 0xF9; // Pressure XLSB register
    const uint8_t BME280_TEMPERATURE_MSB = 0xFA; // Temperature MSB register
    const uint8_t BME280_TEMPERATURE_LSB = 0xFB; // Temperature LSB register
    const uint8_t BME280_TEMPERATURE_XLSB = 0xFC; // Temperature XLSB register
    const uint8_t BME280_HUMIDITY_MSB = 0xFD; // Humidity MSB register
    const uint8_t BME280_HUMIDITY_LSB = 0xFE; // Humidity LSB register

    const uint8_t SPI_CS_PIN = 10;
    const uint8_t LED_PIN = LED_BUILTIN;
    const float TEMP_MIN_C = 26.0f;
    const float TEMP_MAX_C = 29.0f;
    const uint32_t BLINK_SLOW_MS = 1000;
    const uint32_t BLINK_FAST_MS = 100;
    const uint32_t SENSOR_READ_INTERVAL_MS = 500;
    const uint32_t SERIAL_BAUD = 115200;
}