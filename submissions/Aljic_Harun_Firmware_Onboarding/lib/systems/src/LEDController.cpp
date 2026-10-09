#include "LEDController.h"

using namespace BMEConstants;

void LEDController::begin() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void LEDController::setTemperature(float tempC)
{
    float t = constrain(tempC, TEMP_MIN_C, TEMP_MAX_C);
    float fraction = (t - TEMP_MIN_C) / (TEMP_MAX_C - TEMP_MIN_C);
    intervalMs = BLINK_SLOW_MS - (uint32_t)(fraction * (BLINK_SLOW_MS - BLINK_FAST_MS));
}

void LEDController::update() {
    uint32_t now = millis();
    if (now - lastToggleMs >= intervalMs)
    {
        lastToggleMs = now;
        ledOn = !ledOn;
        digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
    }
}