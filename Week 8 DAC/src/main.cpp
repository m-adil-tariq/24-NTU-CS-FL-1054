#include <Arduino.h>

#define DAC_PIN 25

void setup()
{
    Serial.begin(115200);
    Serial.println("ESP32 DAC LED Test");
    digitalWrite(DAC_PIN, 0);
    delay(1000);
    digitalWrite(DAC_PIN, 1);
    delay(1000);
}

void loop()
{
    int values[] = {0, 64, 128, 192, 255};

    for (int i = 0; i < 5; i++)
    {
        dacWrite(DAC_PIN, values[i]);
        Serial.print("DAC Value: ");
        Serial.println(values[i]);

        delay(2000);
    }
}