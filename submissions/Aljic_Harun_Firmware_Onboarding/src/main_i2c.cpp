#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using namespace BMEConstants;

static uint32_t lastReadMs = 0;

void setup()
{
    Serial.begin(SERIAL_BAUD);
    LEDControllerInstance::instance().begin();
    
    if(!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 not found over I2C!");
        while (true); {delay(10);}
    }
}

void loop()
{
    uint32_t now = millis();
    if (now - lastReadMs >= SENSOR_READ_INTERVAL_MS)
    {
        lastReadMs = now;
        float tempC = BMEI2CInterfaceInstance::instance().readTemperature();
        Serial.print("Temperature: ");
        Serial.print(tempC);
        Serial.println(" °C");
        LEDControllerInstance::instance().setTemperature(tempC);
    }
    LEDControllerInstance::instance().update();
}