/*

  This is a library for the BH1750FVI Digital Light Sensor
  breakout board.

  The board uses I2C for communication. 2 pins are required to
  interface to the device.

  Datasheet: http://rohmfs.rohm.com/en/products/databook/datasheet/ic/sensor/light/bh1750fvi-e.pdf

  Written by Christopher Laws, March, 2013.

*/

#ifndef BH1750_h
#define BH1750_h

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Wire.h"

// Uncomment, to enable debug messages
// #define BH1750_DEBUG

// No active state
#define BH1750_POWER_DOWN 0x00

// Wating for measurment command
#define BH1750_POWER_ON 0x01

// Reset data register value - not accepted in POWER_DOWN mode
#define BH1750_RESET 0x07

// Start measurement at 1lx resolution. Measurement time is approx 120ms.
#define BH1750_CONTINUOUS_HIGH_RES_MODE  0x10

// Start measurement at 0.5lx resolution. Measurement time is approx 120ms.
#define BH1750_CONTINUOUS_HIGH_RES_MODE_2  0x11

// Start measurement at 4lx resolution. Measurement time is approx 16ms.
#define BH1750_CONTINUOUS_LOW_RES_MODE  0x13

// Start measurement at 1lx resolution. Measurement time is approx 120ms.
// Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE  0x20

// Start measurement at 0.5lx resolution. Measurement time is approx 120ms.
// Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE_2  0x21

// Start measurement at 1lx resolution. Measurement time is approx 120ms.
// Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_LOW_RES_MODE  0x23

class BH1750 {

  public:
    BH1750 (byte addr = 0x23);
    #if defined(ARDUINO_ARCH_ESP8266)
    /* ==== On esp8266 it is possible to define I2C pins ==== */
    void begin (uint8_t SDA, uint8_t SCL, uint8_t mode = BH1750_CONTINUOUS_HIGH_RES_MODE);
    #endif
    void begin (uint8_t mode = BH1750_CONTINUOUS_HIGH_RES_MODE);
    void configure (uint8_t mode);
    uint16_t readLightLevel(void);

  private:
    int BH1750_I2CADDR;
    uint8_t BH1750_MODE;

};

#endif
