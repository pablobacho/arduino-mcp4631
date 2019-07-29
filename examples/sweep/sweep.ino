/**
 * sweep.ino - An example of MCP4631 library
 * 
 * (C) 2019 - Pablo Bacho <pablo@pablobacho.com>
 * This code is licensed under the MIT License.
 */

#include <MCP4631.h>

#define MCP4631_I2C_ADDRESS 0x2A // Change this to your device's I²C address

MCP4631 mcp4631(MCP4631_I2C_ADDRESS);

void setup() {
  Serial.begin(9600); // Initialize serial port to print information
  mcp4631.begin(); // Initialize the MCP4631
}

void loop() {
  // Increment wiper value from 0 to 128 and print info
  for(int potValue=0; potValue < 128; potValue++) {
    mcp4631.write(WIPER_0, potValue); // Writes potValue on WIPER_0
    mcp4631.write(WIPER_1, potValue); // Writes potValue on WIPER_1
    // Print [written value] / [read wiper 0] / [read wiper 1]
    Serial.print(potValue);
    Serial.print(" / ");
    Serial.print(mcp4631.read(WIPER_0));
    Serial.print(" / ");
    Serial.println(mcp4631.read(WIPER_1));
    delay(50);
  }
  
  // Decrement wiper value from 128 to 0 and print info
  for(int potValue=128; potValue > 0; potValue--) {
    mcp4631.write(WIPER_0, potValue); 
    mcp4631.write(WIPER_1, potValue);
    // Print [written value] / [read wiper 0] / [read wiper 1]
    Serial.print(potValue);
    Serial.print(" / ");
    Serial.print(mcp4631.read(WIPER_0));
    Serial.print(" / ");
    Serial.println(mcp4631.read(WIPER_1));
    delay(50);
  }
}