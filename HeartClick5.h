#ifndef HEARTCLICK5_H
#define HEARTCLICK5_H

#include <Arduino.h>
#include <Wire.h>

class HeartClick5 {
public:
    // Constructor
    HeartClick5(uint8_t heartClick5_ID);

    // Initialization
    bool begin();

    // Getter Functions 3 byte
    int32_t getLed2Val();
    int32_t getAled2ValLed3Val();
    int32_t getLed1Val();
    int32_t getAled1Val();
    int32_t getLed2MinusAled2Val();
    int32_t getLed1MinusAled1Val();

    // Getter Functions 2 byte
    int16_t getLed2StartControl();
    int16_t getLed2EndControl();
    int16_t getLed1LedStartControl();
    int16_t getLed1LedEndControl();
    int16_t getAled2Led3StartControl();
    int16_t getAled2Led3EndControl();
    int16_t getLed1StartControl();
    int16_t getLed1EndControl();
    int16_t getLed2LedStartControl();
    int16_t getLed2LedEndControl();
    int16_t getAled1StartControl();
    int16_t getAled1EndControl();
    int16_t getLed2ConvStartControl();
    int16_t getLed2ConvEndControl();
    int16_t getAled2Led3ConvStartControl();
    int16_t getAled2Led3ConvEndControl();
    int16_t getLed1ConvStartControl();
    int16_t getLed1ConvEndControl();
    int16_t getAled1ConvStartControl();
    int16_t getAled1ConvEndControl();
    int16_t getAdcResetStartControlT0();
    int16_t getAdcResetEndControlT0();
    int16_t getAdcResetStartControlT1();
    int16_t getAdcResetEndControlT1();
    int16_t getAdcResetStartControlT2();
    int16_t getAdcResetEndControlT2();
    int16_t getAdcResetStartControlT3();
    int16_t getAdcResetEndControlT3();
    int16_t getProximityPulseControl();
    int16_t getTimerControl();

    // Setter Functions
    void setLed2StartControl(uint32_t value);
    void setLed2EndControl(uint32_t value);
    void setLed1LedStartControl(uint32_t value);
    void setLed1LedEndControl(uint32_t value);
    void setAled2Led3StartControl(uint32_t value);
    void setAled2Led3EndControl(uint32_t value);
    void setLed1StartControl(uint32_t value);
    void setLed1EndControl(uint32_t value);
    void setLed2LedStartControl(uint32_t value);
    void setLed2LedEndControl(uint32_t value);
    void setAled1StartControl(uint32_t value);
    void setAled1EndControl(uint32_t value);
    void setLed2ConvStartControl(uint32_t value);
    void setLed2ConvEndControl(uint32_t value);
    void setAled2Led3ConvStartControl(uint32_t value);
    void setAled2Led3ConvEndControl(uint32_t value);
    void setLed1ConvStartControl(uint32_t value);
    void setLed1ConvEndControl(uint32_t value);
    void setAled1ConvStartControl(uint32_t value);
    void setAled1ConvEndControl(uint32_t value);
    void setAdcResetStartControlT0(uint32_t value);
    void setAdcResetEndControlT0(uint32_t value);
    void setAdcResetStartControlT1(uint32_t value);
    void setAdcResetEndControlT1(uint32_t value);
    void setAdcResetStartControlT2(uint32_t value);
    void setAdcResetEndControlT2(uint32_t value);
    void setAdcResetStartControlT3(uint32_t value);
    void setAdcResetEndControlT3(uint32_t value);
    void setProximityPulseControl(uint32_t value);
    void setTimerControl(uint32_t value);

private:
    uint8_t sensor_ID;

    void i2c_write(uint8_t addr, uint32_t bytes[3], uint8_t deviceID);
    int16_t i2c_read_2(uint8_t addr, uint8_t deviceID);
    int32_t i2c_read_3(uint8_t addr, uint8_t deviceID);

};

#endif // HEARTCLICK5_H
