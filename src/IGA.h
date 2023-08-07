#ifndef IGA_H
#define IGA_H

#include "xbm.h"
#include <Wire.h>
#include <ArduinoJson.h>


class IGA {
public:
    IGA();
    bool begin();
    bool getData(uint16_t &co2, uint16_t &tvoc);
    bool getJSON(JsonObject &doc);

private:
    void writeCommand(uint16_t command);
    bool readData(uint16_t data[], uint8_t numWords);
    bool wireping(uint8_t address);
    bool uninitialized = true;
};

#endif // IGA_H
