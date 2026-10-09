#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
    public:
        LEDController() = default;

        void begin();
        void setTemperature(float tempC);
        void update();
    
    private:
        uint32_t intervalMs = BMEConstants::BLINK_SLOW_MS;
        uint32_t lastToggleMs = 0;
        bool ledOn = false;
};
using LEDControllerInstance = etl::singleton<LEDController>;