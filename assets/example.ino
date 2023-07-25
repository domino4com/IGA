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
    uint16_t co2, tvoc;

    if (iga.getData(co2, tvoc)) {
        Serial.printf("CO2 concentration: %d ppm, TVOC concentration: %d ppb\n", co2, tvoc);
    } else {
        Serial.println("Failed to IGA data.");
    }

    delay(2000);
}
