#include <main.h>
#include "as726x.h"

extern hi2c2;

void write(uint8_t virtualReg, uint8_t data)
{
    volatile uint8_t status;
    virtualReg |= 0x80;

    while (1)
    {

        HAL_I2C_Mem_Read(&hi2c2, AS726x_READ_ADDRESS, AS726X_SLAVE_STATUS_REG, 1, &status, 1, 1000);
        if ((status & AS726X_SLAVE_TX_VALID) == 0)
        {
            break;
        }
    }

    HAL_I2C_Mem_Write(&hi2c2, AS726x_WRITE_ADDRESS, AS726X_SLAVE_WRITE_REG, 1, &virtualReg, 1, 1000);

    while (1)
    {
        HAL_I2C_Mem_Read(&hi2c2, AS726x_READ_ADDRESS, AS726X_SLAVE_STATUS_REG, 1, &status, 1, 1000);
        if ((status & AS726X_SLAVE_TX_VALID) == 0)
        {
            break;
        }
    }

    HAL_I2C_Mem_Write(&hi2c2, AS726x_WRITE_ADDRESS, AS726X_SLAVE_WRITE_REG, 1, &data, 1, 1000);
}

uint8_t read(uint8_t virtualReg)
{
    volatile uint8_t status, data;

    while (1)
    {
        HAL_I2C_Mem_Read(&hi2c2, AS726x_READ_ADDRESS, AS726X_SLAVE_STATUS_REG, 1, &status, 1, 1000);
        if ((status & AS726X_SLAVE_TX_VALID) == 0)
        {
            break;
        }
    }

    HAL_I2C_Mem_Write(&hi2c2, AS726x_WRITE_ADDRESS, AS726X_SLAVE_WRITE_REG, 1, &virtualReg, 1, 1000);

    while (1)
    {
        HAL_I2C_Mem_Read(&hi2c2, AS726x_READ_ADDRESS, AS726X_SLAVE_STATUS_REG, 1, &status, 1, 1000);
        if ((status & AS726X_SLAVE_RX_VALID) == 0)
        {
            break;
        }
    }

    HAL_I2C_Mem_Read(&hi2c2, AS726x_READ_ADDRESS, AS726X_SLAVE_READ_REG, 1, &data, 1, 1000);

    return data;
}
