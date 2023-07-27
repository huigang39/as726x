#include <stdint.h>

#define AS726x_WRITE_ADDRESS (0x49 << 1)
#define AS726x_READ_ADDRESS (0x49 << 1 | 1)

enum
{
    AS726X_HW_VERSION = 0x00,
    AS726X_FW_VERSION = 0x02,
    AS726X_CONTROL_SETUP = 0x04,
    AS726X_INT_T = 0x05,
    AS726X_DEVICE_TEMP = 0x06,
    AS726X_LED_CONTROL = 0x07,

    // for reading sensor data
    AS7262_V_HIGH = 0x08,
    AS7262_V_LOW = 0x09,
    AS7262_B_HIGH = 0x0A,
    AS7262_B_LOW = 0x0B,
    AS7262_G_HIGH = 0x0C,
    AS7262_G_LOW = 0x0D,
    AS7262_Y_HIGH = 0x0E,
    AS7262_Y_LOW = 0x0F,
    AS7262_O_HIGH = 0x10,
    AS7262_O_LOW = 0x11,
    AS7262_R_HIGH = 0x12,
    AS7262_R_LOW = 0x13,

    AS7262_V_CAL = 0x14,
    AS7262_B_CAL = 0x18,
    AS7262_G_CAL = 0x1C,
    AS7262_Y_CAL = 0x20,
    AS7262_O_CAL = 0x24,
    AS7262_R_CAL = 0x28
};

enum
{
    AS726X_SLAVE_STATUS_REG = 0x00,
    AS726X_SLAVE_WRITE_REG = 0x01,
    AS726X_SLAVE_READ_REG = 0x02,
    AS726X_SLAVE_TX_VALID = 0x02,
    AS726X_SLAVE_RX_VALID = 0x01,
};

enum
{
    AS7262_VIOLET = 0x08,
    AS7262_BLUE = 0x0A,
    AS7262_GREEN = 0x0C,
    AS7262_YELLOW = 0x0E,
    AS7262_ORANGE = 0x10,
    AS7262_RED = 0x12,
    AS7262_VIOLET_CALIBRATED = 0x14,
    AS7262_BLUE_CALIBRATED = 0x18,
    AS7262_GREEN_CALIBRATED = 0x1C,
    AS7262_YELLOW_CALIBRATED = 0x20,
    AS7262_ORANGE_CALIBRATED = 0x24,
    AS7262_RED_CALIBRATED = 0x28,
};

enum conversion_types
{
    MODE_0 = 0b00,
    MODE_1 = 0b01,
    MODE_2 = 0b10, // 默认
    ONE_SHOT = 0b11,
};

enum channel_gain
{
    GAIN_1X = 0b00, // 默认
    GAIN_3X7 = 0b01,
    GAIN_16X = 0b10,
    GAIN_64X = 0b11,
};

enum ind_led_current_limits
{
    LIMIT_1MA = 0b00, // 默认
    LIMIT_2MA = 0b01,
    LIMIT_4MA = 0b10,
    LIMIT_8MA = 0b11,
};

enum drv_led_current_limits
{
    LIMIT_12MA5 = 0b00, // 默认
    LIMIT_25MA = 0b01,
    LIMIT_50MA = 0b10,
    LIMIT_100MA = 0b11,
};

enum
{
    AS726x_VIOLET = 0,
    AS726x_BLUE,
    AS726x_GREEN,
    AS726x_YELLOW,
    AS726x_ORANGE,
    AS726x_RED,
};

#define AS726x_INTEGRATION_TIME_MULT 2.8 // 用于积分时间的乘数
#define AS726x_NUM_CHANNELS 6            // 通道数量

void write(uint8_t virtualReg, uint8_t d);
uint8_t read(uint8_t virtualReg);
