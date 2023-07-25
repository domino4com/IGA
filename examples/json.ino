#include <ArduinoJson.h>
#include <Wire.h>

#include "IGA.h"
IGA iga;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nIGA Test\n");

    Wire.setPins(I2C_SDA, I2C_SCL);
    Wire.begin();

    if (iga.begin()) {
        Serial.println("IGA sensor initialized successfully.");
    } else {
        Serial.println("Failed to initialize IGA sensor!");
        exit(0);
    }
}

void loop() {
    StaticJsonDocument<256> doc;
    JsonObject root = doc.to<JsonObject>();

    if (iga.getJSON(root)) {
        serializeJsonPretty(root, Serial);
        Serial.println();
    } else {
        Serial.println("Failed to IGA data.");
    }

    delay(2000);
}
