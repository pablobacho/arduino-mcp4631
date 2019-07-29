/**
 * MCP4631.h - MCP4631 library
 * 
 * (C) 2019 - Pablo Bacho <pablo@pablobacho.com>
 * This code is licensed under the MIT License.
 */

#ifndef _MCP4631_H_
#define _MCP4631_H_

#include "Arduino.h"
#include <Wire.h>

typedef enum{WIPER_0 = 0, WIPER_1 = 1} Wiper;

class MCP4631 {
    public:
        /**
         * Constructor specifying I²C bus
         */
        MCP4631(TwoWire * theI2C, byte address);

        /**
         * Constructor using the default I²C bus
         */
        MCP4631(byte address);

        /**
         * Initialize module
         */
        void begin();

        /**
         * Read value from wiper. From 0 to 128.
         */
        int read(Wiper wiper);

        /**
         * Write wiper value. From 0 to 128.
         */
        void write(Wiper wiper, int value);

    private:
        static const uint8_t WIPER0_WRITE_CMD = 0x00;
        static const uint8_t WIPER0_READ_CMD = 0x0C;
        static const uint8_t WIPER1_WRITE_CMD = 0x10;
        static const uint8_t WIPER1_READ_CMD = 0x1C;
        static const uint8_t TCON_WRITE_CMD = 0x40;
        static const uint8_t TCON_READ_CMD = 0x4C;
        byte _i2caddr;
        TwoWire * _i2c;
};


#endif // _MCP4631_H_