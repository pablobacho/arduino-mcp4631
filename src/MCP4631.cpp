/**
 * MCP4631.cpp - MCP4631 library
 * 
 * (C) 2019 - Pablo Bacho <pablo@pablobacho.com>
 * This code is licensed under the MIT License.
 */

#include "MCP4631.h"

MCP4631::MCP4631(TwoWire * theI2C, byte address) {
    _i2c = theI2C;
    _i2caddr = address;
}

MCP4631::MCP4631(byte address) {
    _i2c = &Wire;
    _i2caddr = address;
}

void MCP4631::begin() {
    _i2c->begin();
}

int MCP4631::read(Wiper wiper) {
    _i2c->beginTransmission(_i2caddr);
    if(wiper == WIPER_0) {
        _i2c->write(byte(WIPER0_READ_CMD)); // Instruction byte
    } else {
        _i2c->write(byte(WIPER1_READ_CMD));
    }
    int err = _i2c->endTransmission(false);

    _i2c->requestFrom((int) _i2caddr, 2, true);
    int value = ((int) _i2c->read()) << 8;
    value |= _i2c->read();

    return value;
}

void MCP4631::write(Wiper wiper, int value) {
    _i2c->beginTransmission(_i2caddr);
    if(wiper == WIPER_0) {
        _i2c->write(byte(WIPER0_WRITE_CMD));
    } else {
        _i2c->write(byte(WIPER1_WRITE_CMD));
    }
    _i2c->write(byte(value));
    int err = _i2c->endTransmission(false);

    return;
}
