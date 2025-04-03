#include "HeartClick5.h" // Assuming we'll create this header

// Constructor for the BMP585 class
HeartClick5::HeartClick5(uint8_t heartClick5_ID)
{
  sensor_ID = heartClick5_ID; // Assign the sensor ID (can either be 0x47 or another value)
}

const uint8_t HR5_REG0H                      = 0x00;
const uint8_t HR5_REG1H                      = 0x01; //LED2STC
const uint8_t HR5_REG2H                      = 0x02; //LED2ENDC
const uint8_t HR5_REG3H                      = 0x03; //LED1LEDSTC
const uint8_t HR5_REG4H                      = 0x04; //LED1LEDENDC
const uint8_t HR5_REG5H                      = 0x05; //ALED2STC\LED3STC
const uint8_t HR5_REG6H                      = 0x06; //ALED2ENDC\LED3ENDC
const uint8_t HR5_REG7H                      = 0x07; //LED1STC
const uint8_t HR5_REG8H                      = 0x08; //LED1ENDC
const uint8_t HR5_REG9H                      = 0x09; //LED2LEDSTC
const uint8_t HR5_REGAH                      = 0x0A; //LED2LEDENDC
const uint8_t HR5_REGBH                      = 0x0B; //ALED1STC
const uint8_t HR5_REGCH                      = 0x0C; //ALED1ENDC
const uint8_t HR5_REGDH                      = 0x0D; //LED2CONVST
const uint8_t HR5_REGEH                      = 0x0E; //LED2CONVEND
const uint8_t HR5_REGFH                      = 0x0F; //ALED2CONVST\LED3CONVST
const uint8_t HR5_REG10H                     = 0x10; //ALED2CONVEND\LED3CONVEND
const uint8_t HR5_REG11H                     = 0x11; //LED1CONVST
const uint8_t HR5_REG12H                     = 0x12; //LED1CONVEND
const uint8_t HR5_REG13H                     = 0x13; //ALED1CONVST
const uint8_t HR5_REG14H                     = 0x14; //ALED1CONVEND
const uint8_t HR5_REG15H                     = 0x15; //ADCRSTSTCT0
const uint8_t HR5_REG16H                     = 0x16; //ADCRSTENDCT0
const uint8_t HR5_REG17H                     = 0x17; //ADCRSTSTCT1
const uint8_t HR5_REG18H                     = 0x18; //ADCRSTENDCT1
const uint8_t HR5_REG19H                     = 0x19; //ADCRSTSTCT2
const uint8_t HR5_REG1AH                     = 0x1A; //ADCRSTENDCT2
const uint8_t HR5_REG1BH                     = 0x1B; //ADCRSTSTCT3
const uint8_t HR5_REG1CH                     = 0x1C; //ADCRSTENDCT3
const uint8_t HR5_REG1DH                     = 0x1D; //PRPCT
const uint8_t HR5_REG1EH                     = 0x1E; //timer controll
const uint8_t HR5_REG20H                     = 0x20;
const uint8_t HR5_REG21H                     = 0x21;
const uint8_t HR5_REG22H                     = 0x22;
const uint8_t HR5_REG23H                     = 0x23;
const uint8_t HR5_REG29H                     = 0x29;

const uint8_t HR5_REG2AH                     = 0x2A;//LED2VAL
const uint8_t HR5_REG2BH                     = 0x2B;//ALED2VAL\ALSED3VAL
const uint8_t HR5_REG2CH                     = 0x2C;//LED1VAL
const uint8_t HR5_REG2DH                     = 0x2D;//ALED1VAL
const uint8_t HR5_REG2EH                     = 0x2E;//LED2-ALED2VAL
const uint8_t HR5_REG2FH                     = 0x2F;//LED1-ALED1VAL

const uint8_t HR5_REG31H                     = 0x31;
const uint8_t HR5_REG32H                     = 0x32;
const uint8_t HR5_REG33H                     = 0x33;
const uint8_t HR5_REG34H                     = 0x34;
const uint8_t HR5_REG35H                     = 0x35;
const uint8_t HR5_REG36H                     = 0x36;
const uint8_t HR5_REG37H                     = 0x37;
const uint8_t HR5_REG39H                     = 0x39;
const uint8_t HR5_REG3AH                     = 0x3A;
const uint8_t HR5_REG3DH                     = 0x3D;
const uint8_t HR5_REG3FH                     = 0x3F;
const uint8_t HR5_REG40H                     = 0x40;

// Global arrays for initial configuration
uint32_t binary_values[][3] = {
    {0b00000000, 0b00000000, 0b00001001}, // HR5_REG0H - Unused
    {0b00000000, 0b00000000, 0b01010000}, // HR5_REG1H - LED2LEDSTC (100)
    {0b00000000, 0b00000001, 0b10001111}, // HR5_REG2H - LED2LEDENDC (399)
    {0b00000000, 0b00000000, 0b01001011}, // HR5_REG3H - LED2STC (75)
    {0b00000000, 0b00000001, 0b10001111}, // HR5_REG4H - LED2ENDC (399)
    {0b00000000, 0b00000001, 0b10101111}, // HR5_REG5H - ADCRSTSTCT0 (431)
    {0b00000000, 0b00000001, 0b10110111}, // HR5_REG6H - ADCRSTENDCT0 (439)
    {0b00000000, 0b00000001, 0b11000110}, // HR5_REG7H - LED2CONVST (454)
    {0b00000000, 0b00000101, 0b10111000}, // HR5_REG8H - LED2CONVEND (1464)
    {0b00000000, 0b00000001, 0b10101111}, // HR5_REG9H - LED3LEDSTC (431)
    {0b00000000, 0b00000011, 0b00100111}, // HR5_REGAH - LED3LEDENDC (807)
    {0b00000000, 0b00000001, 0b11110101}, // HR5_REGBH - ALED2STC / LED3STC (501)
    {0b00000000, 0b00000011, 0b00100000}, // HR5_REGCH - ALED2ENDC / LED3ENDC (800)
    {0b00000000, 0b00000101, 0b11000100}, // HR5_REGDH - ADCRSTSTCT1 (1476)
    {0b00000000, 0b00000101, 0b11001010}, // HR5_REGEH - ADCRSTENDCT1 (1482)
    {0b00000000, 0b00000101, 0b11010100}, // HR5_REGFH - LED3CONVST / ALED2CONVST (1492)
    {0b00000000, 0b00001001, 0b11101001}, // HR5_REG10H - LED3CONVEND / ALED2CONVEND (2537)
    {0b00000000, 0b00001001, 0b11110000}, // HR5_REG11H - LED1CONVST (2544)
    {0b00000000, 0b00001110, 0b00010011}, // HR5_REG12H - LED1CONVEND (3603)
    {0b00000000, 0b00001110, 0b00011100}, // HR5_REG13H - ALED1CONVST (3612)
    {0b00000000, 0b00010010, 0b00111111}, // HR5_REG14H - ALED1CONVEND (4675)
    {0b00000000, 0b00000001, 0b10010001}, // HR5_REG15H - ADCRSTSTCT2 (401)
    {0b00000000, 0b00000001, 0b10010111}, // HR5_REG16H - ADCRSTENDCT2 (407)
    {0b00000000, 0b00000101, 0b10111101}, // HR5_REG17H - ADCRSTSTCT3 (1469)
    {0b00000000, 0b00000101, 0b11000011}, // HR5_REG18H - ADCRSTENDCT3 (1475)
    {0b00000000, 0b00001001, 0b11101001}, // HR5_REG19H - LED1STC (2537)
    {0b00000000, 0b00001001, 0b11101111}, // HR5_REG1AH - LED1ENDC (2543)
    {0b00000000, 0b00001110, 0b00010101}, // HR5_REG1BH - ALED1STC (3605)
    {0b00000000, 0b00001110, 0b00011011}, // HR5_REG1CH - ALED1ENDC (3611)
    {0b00000000, 0b10011100, 0b00111110}, // HR5_REG1DH - PRPCT (39999)
    {0b00000000, 0b00000001, 0b00000011}, // HR5_REG1EH - Timer Control
    {0b10000000, 0b00000000, 0b00000011}, // HR5_REG20H - Unspecified
    {0b00000000, 0b00000000, 0b00000011}, // HR5_REG21H - Unspecified
    {0b00000001, 0b10110110, 0b11011001}, // HR5_REG22H - LED Currents (LED3, LED2, LED1)
    {0b00010000, 0b01000010, 0b00011000}, // HR5_REG23H - Dynamic Engine Enable
    {0b00000000, 0b00000000, 0b00000000}, // HR5_REG29H - CLKDIV Output Control
    {0b00000000, 0b00000000, 0b00000000}, // HR5_REG31H - Unspecified
    {0b00000000, 0b00010101, 0b01011111}, // HR5_REG32H - PDNCYCLESTC
    {0b00000000, 0b10011001, 0b00011110}, // HR5_REG33H - PDNCYCLEENDC
    {0b00000000, 0b00000000, 0b00000000}, // HR5_REG34H - Unspecified
    {0b00000000, 0b00000000, 0b00000000}, // HR5_REG35H - Unspecified
    {0b00000000, 0b00000001, 0b10010000}, // HR5_REG36H - LED3LEDSTC
    {0b00000000, 0b00000011, 0b00011111}, // HR5_REG37H - LED3LEDENDC
    {0b00000000, 0b00000000, 0b00000000}, // HR5_REG39H - Unspecified
    {0b00000000, 0b00000000, 0b00000000}  // HR5_REG3AH - Unspecified};
};

int register_addresses[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1E, 0x20, 0x21, 0x22, 0x23, 0x29, 0x31, 0x32, 0x33, 0x34,
    0x35, 0x36, 0x37, 0x39, 0x3A
};

int16_t respekt = 44;
int16_t adidas = 2412;

// Function to write 3 bytes to the sensor over I2C
void HeartClick5::i2c_write(uint8_t addr, uint32_t bytes[3], uint8_t deviceID)
{
    Wire.beginTransmission(deviceID); // Begin I2C transmission to the device
    Wire.write(addr);                 // Write the register address
    for (int i = 0; i <= 2; i++) {
        Wire.write((uint8_t)bytes[i]);
    };
    Wire.endTransmission();           // End the I2C transmission
}

// Function to read 3 bytes from the sensor over I2C
int32_t HeartClick5::i2c_read_3(uint8_t addr, uint8_t deviceID)
{
    Wire.beginTransmission(deviceID); // Begin I2C transmission to the device
    Wire.write(addr);                 // Write the register address
    Wire.endTransmission(false);      // End transmission without releasing the bus
    Wire.requestFrom(deviceID, 3);    // Request 3 bytes of data from the device
    if (Wire.available() == 3)        // Check if 3 bytes are available
    {
        // Read and combine the 3 bytes into a 24-bit value
        uint32_t rawValue = (Wire.read() << 16) | (Wire.read() << 8) | Wire.read();
        // Check if the value is negative (MSB of 24-bit is 1)
        if (rawValue & 0x800000)
        {
            // Pad with 8 ones for negative value to make it a signed 32-bit integer
            return (int32_t)(rawValue | 0xFF000000);
        }
        else
        {
            // Return the positive value as is
            return (int32_t)rawValue;
        }
    }
    else
    {
        return (int32_t)(0xFFFFFFFF); // Return 0xFFFFFFFF if data is not available
    }
}

// Function to read 2 bytes from the sensor over I2C
int16_t HeartClick5::i2c_read_2(uint8_t addr, uint8_t deviceID)
{
    Wire.beginTransmission(deviceID); // Begin I2C transmission to the device
    Wire.write(addr);                 // Write the register address
    Wire.endTransmission(false);      // End transmission without releasing the bus
    Wire.requestFrom(deviceID, 2);    // Request 2 bytes of data from the device
    if (Wire.available() == 2)        // Check if 2 bytes are available
    {
        // Read and combine the 2 bytes into a 24-bit value
        uint16_t rawValue = (Wire.read() << 8 | Wire.read());
        // Check if the value is negative (MSB of 16-bit is 1)
        if (rawValue & 0x8000)
            {
                // Pad with 16 ones for negative value
                return (int16_t)rawValue;
            }
        else
            {
                // Pad with 16 zeros for positive value
                return (int16_t)rawValue;
            }
    }
    else
    {
            return (int16_t)(0xFFFF); // Return 0xFFFF if data is not available
    }
}

bool HeartClick5::begin() {
    
    for (int i = 0; i < sizeof(register_addresses) / sizeof(register_addresses[0]); i++) {
        i2c_write(register_addresses[i], binary_values[i], sensor_ID);
    };

    return true;
};


// 3-byte Getter Functions Only
int32_t HeartClick5::getLed2Val() {
    return i2c_read_3(HR5_REG2AH, sensor_ID);
}

int32_t HeartClick5::getAled2ValLed3Val() {
    return i2c_read_3(HR5_REG2BH, sensor_ID);
}

int32_t HeartClick5::getLed1Val() {
    return i2c_read_3(HR5_REG2CH, sensor_ID);
}

int32_t HeartClick5::getAled1Val() {
    return i2c_read_3(HR5_REG2DH, sensor_ID);
}

int32_t HeartClick5::getLed2MinusAled2Val() {
    return i2c_read_3(HR5_REG2EH, sensor_ID);
}

int32_t HeartClick5::getLed1MinusAled1Val() {
    return i2c_read_3(HR5_REG2FH, sensor_ID);
}

// 2-byte Getter Functions Only

int16_t HeartClick5::getLed2StartControl() {
    return i2c_read_2(HR5_REG1H, sensor_ID);
}

int16_t HeartClick5::getLed2EndControl() {
    return i2c_read_2(HR5_REG2H, sensor_ID);
}

int16_t HeartClick5::getLed1LedStartControl() {
    return i2c_read_2(HR5_REG3H, sensor_ID);
}

int16_t HeartClick5::getLed1LedEndControl() {
    return i2c_read_2(HR5_REG4H, sensor_ID);
}

int16_t HeartClick5::getAled2Led3StartControl() {
    return i2c_read_2(HR5_REG5H, sensor_ID);
}

int16_t HeartClick5::getAled2Led3EndControl() {
    return i2c_read_2(HR5_REG6H, sensor_ID);
}

int16_t HeartClick5::getLed1StartControl() {
    return i2c_read_2(HR5_REG7H, sensor_ID);
}

int16_t HeartClick5::getLed1EndControl() {
    return i2c_read_2(HR5_REG8H, sensor_ID);
}

int16_t HeartClick5::getLed2LedStartControl() {
    return i2c_read_2(HR5_REG9H, sensor_ID);
}

int16_t HeartClick5::getLed2LedEndControl() {
    return i2c_read_2(HR5_REGAH, sensor_ID);
}

int16_t HeartClick5::getAled1StartControl() {
    return i2c_read_2(HR5_REGBH, sensor_ID);
}

int16_t HeartClick5::getAled1EndControl() {
    return i2c_read_2(HR5_REGCH, sensor_ID);
}

int16_t HeartClick5::getLed2ConvStartControl() {
    return i2c_read_2(HR5_REGDH, sensor_ID);
}

int16_t HeartClick5::getLed2ConvEndControl() {
    return i2c_read_2(HR5_REGEH, sensor_ID);
}

int16_t HeartClick5::getAled2Led3ConvStartControl() {
    return i2c_read_2(HR5_REGFH, sensor_ID);
}

int16_t HeartClick5::getAled2Led3ConvEndControl() {
    return i2c_read_2(HR5_REG10H, sensor_ID);
}

int16_t HeartClick5::getLed1ConvStartControl() {
    return i2c_read_2(HR5_REG11H, sensor_ID);
}

int16_t HeartClick5::getLed1ConvEndControl() {
    return i2c_read_2(HR5_REG12H, sensor_ID);
}

int16_t HeartClick5::getAled1ConvStartControl() {
    return i2c_read_2(HR5_REG13H, sensor_ID);
}

int16_t HeartClick5::getAled1ConvEndControl() {
    return i2c_read_2(HR5_REG14H, sensor_ID);
}

int16_t HeartClick5::getAdcResetStartControlT0() {
    return i2c_read_2(HR5_REG15H, sensor_ID);
}

int16_t HeartClick5::getAdcResetEndControlT0() {
    return i2c_read_2(HR5_REG16H, sensor_ID);
}

int16_t HeartClick5::getAdcResetStartControlT1() {
    return i2c_read_2(HR5_REG17H, sensor_ID);
}

int16_t HeartClick5::getAdcResetEndControlT1() {
    return i2c_read_2(HR5_REG18H, sensor_ID);
}

int16_t HeartClick5::getAdcResetStartControlT2() {
    return i2c_read_2(HR5_REG19H, sensor_ID);
}

int16_t HeartClick5::getAdcResetEndControlT2() {
    return i2c_read_2(HR5_REG1AH, sensor_ID);
}

int16_t HeartClick5::getAdcResetStartControlT3() {
    return i2c_read_2(HR5_REG1BH, sensor_ID);
}

int16_t HeartClick5::getAdcResetEndControlT3() {
    return i2c_read_2(HR5_REG1CH, sensor_ID);
}

int16_t HeartClick5::getProximityPulseControl() {
    return i2c_read_2(HR5_REG1DH, sensor_ID);
}

int16_t HeartClick5::getTimerControl() {
    return i2c_read_2(HR5_REG1EH, sensor_ID);
}


// Setter functions

// Setter functions corresponding to each register

void HeartClick5::setLed2StartControl(uint32_t value) {
    i2c_write(HR5_REG1H, binary_values[1], sensor_ID);
}

void HeartClick5::setLed2EndControl(uint32_t value) {
    i2c_write(HR5_REG2H, binary_values[2], sensor_ID);
}

void HeartClick5::setLed1LedStartControl(uint32_t value) {
    i2c_write(HR5_REG3H, binary_values[3], sensor_ID);
}

void HeartClick5::setLed1LedEndControl(uint32_t value) {
    i2c_write(HR5_REG4H, binary_values[4], sensor_ID);
}

void HeartClick5::setAled2Led3StartControl(uint32_t value) {
    i2c_write(HR5_REG5H, binary_values[5], sensor_ID);
}

void HeartClick5::setAled2Led3EndControl(uint32_t value) {
    i2c_write(HR5_REG6H, binary_values[6], sensor_ID);
}

void HeartClick5::setLed1StartControl(uint32_t value) {
    i2c_write(HR5_REG7H, binary_values[7], sensor_ID);
}

void HeartClick5::setLed1EndControl(uint32_t value) {
    i2c_write(HR5_REG8H, binary_values[8], sensor_ID);
}

void HeartClick5::setLed2LedStartControl(uint32_t value) {
    i2c_write(HR5_REG9H, binary_values[9], sensor_ID);
}

void HeartClick5::setLed2LedEndControl(uint32_t value) {
    i2c_write(HR5_REGAH, binary_values[10], sensor_ID);
}

void HeartClick5::setAled1StartControl(uint32_t value) {
    i2c_write(HR5_REGBH, binary_values[11], sensor_ID);
}

void HeartClick5::setAled1EndControl(uint32_t value) {
    i2c_write(HR5_REGCH, binary_values[12], sensor_ID);
}

void HeartClick5::setLed2ConvStartControl(uint32_t value) {
    i2c_write(HR5_REGDH, binary_values[13], sensor_ID);
}

void HeartClick5::setLed2ConvEndControl(uint32_t value) {
    i2c_write(HR5_REGEH, binary_values[14], sensor_ID);
}

void HeartClick5::setAled2Led3ConvStartControl(uint32_t value) {
    i2c_write(HR5_REGFH, binary_values[15], sensor_ID);
}

void HeartClick5::setAled2Led3ConvEndControl(uint32_t value) {
    i2c_write(HR5_REG10H, binary_values[16], sensor_ID);
}

void HeartClick5::setLed1ConvStartControl(uint32_t value) {
    i2c_write(HR5_REG11H, binary_values[17], sensor_ID);
}

void HeartClick5::setLed1ConvEndControl(uint32_t value) {
    i2c_write(HR5_REG12H, binary_values[18], sensor_ID);
}

void HeartClick5::setAled1ConvStartControl(uint32_t value) {
    i2c_write(HR5_REG13H, binary_values[19], sensor_ID);
}

void HeartClick5::setAled1ConvEndControl(uint32_t value) {
    i2c_write(HR5_REG14H, binary_values[20], sensor_ID);
}

void HeartClick5::setAdcResetStartControlT0(uint32_t value) {
    i2c_write(HR5_REG15H, binary_values[21], sensor_ID);
}

void HeartClick5::setAdcResetEndControlT0(uint32_t value) {
    i2c_write(HR5_REG16H, binary_values[22], sensor_ID);
}

void HeartClick5::setAdcResetStartControlT1(uint32_t value) {
    i2c_write(HR5_REG17H, binary_values[23], sensor_ID);
}

void HeartClick5::setAdcResetEndControlT1(uint32_t value) {
    i2c_write(HR5_REG18H, binary_values[24], sensor_ID);
}

void HeartClick5::setAdcResetStartControlT2(uint32_t value) {
    i2c_write(HR5_REG19H, binary_values[25], sensor_ID);
}

void HeartClick5::setAdcResetEndControlT2(uint32_t value) {
    i2c_write(HR5_REG1AH, binary_values[26], sensor_ID);
}

void HeartClick5::setAdcResetStartControlT3(uint32_t value) {
    i2c_write(HR5_REG1BH, binary_values[27], sensor_ID);
}

void HeartClick5::setAdcResetEndControlT3(uint32_t value) {
    i2c_write(HR5_REG1CH, binary_values[28], sensor_ID);
}

void HeartClick5::setProximityPulseControl(uint32_t value) {
    i2c_write(HR5_REG1DH, binary_values[29], sensor_ID);
}

void HeartClick5::setTimerControl(uint32_t value) {
    i2c_write(HR5_REG1EH, binary_values[30], sensor_ID);
}
