/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "platform.h"

#include "config/parameter_group.h"
#include "drivers/io_types.h"
#include "drivers/rcc_types.h"

#ifndef I2C_DEVICE
#define I2C_DEVICE I2CINVALID
#endif

typedef enum I2CDevice {
    I2CINVALID = -1,
    I2CDEV_1   = 0,
    I2CDEV_2,
    I2CDEV_3,
    I2CDEV_4,
} I2CDevice;

#if defined(STM32F1) || defined(STM32F3)
#define I2CDEV_COUNT 2
#elif defined(STM32F4)
#define I2CDEV_COUNT 3
#elif defined(STM32F7)
#define I2CDEV_COUNT 4
#else
#define I2CDEV_COUNT 4
#endif

typedef struct i2cConfig_s {
    ioTag_t ioTagScl[I2CDEV_COUNT];
    ioTag_t ioTagSda[I2CDEV_COUNT];
    bool overClock[I2CDEV_COUNT];
    bool pullUp[I2CDEV_COUNT];
} i2cConfig_t;

void i2cHardwareConfigure(void);
void i2cInit(I2CDevice device);
bool i2cWriteBuffer(I2CDevice device, uint8_t addr_, uint8_t reg_, uint8_t len_, uint8_t *data);
bool i2cWrite(I2CDevice device, uint8_t addr_, uint8_t reg, uint8_t data);
bool i2cRead(I2CDevice device, uint8_t addr_, uint8_t reg, uint8_t len, uint8_t* buf);

uint16_t i2cGetErrorCounter(void);
