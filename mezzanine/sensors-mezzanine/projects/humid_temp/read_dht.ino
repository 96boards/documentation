#include "DHT.h"

DHT dht(A0, DHT11);

void setup()
{
        Serial.begin(9600);
        dht.begin();
}

void loop()
{
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        // check if valid, if NaN (not a number) then something went wrong!
        if (isnan(t) || isnan(h)) {
                Serial.println("Failed to read from DHT");
                return;
        }

        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(t);
        Serial.println(" *C");
        delay(2000);
}

