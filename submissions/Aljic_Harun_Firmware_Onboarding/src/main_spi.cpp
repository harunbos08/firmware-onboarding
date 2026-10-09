#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using namespace BMEConstants;
static uint32_t lastReadMs = 0;

void setup()
{
    Serial.begin(SERIAL_BAUD);
    LEDControllerInstance::instance().begin();
    
    if(!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 not found over SPI!");
        while (true); {delay(10);}
    }
}

void loop()
{
    uint32_t now = millis();
    if (now - lastReadMs >= SENSOR_READ_INTERVAL_MS)
    {
        lastReadMs = now;
        float tempC = BMESPIInterfaceInstance::instance().readTemperature();
        Serial.print("Temperature: ");
        Serial.print(tempC);
        Serial.println(" °C");
        LEDControllerInstance::instance().setTemperature(tempC);
    }
    LEDControllerInstance::instance().update();
}