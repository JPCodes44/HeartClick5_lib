
# HeartClick5 Arduino Driver

This Arduino library enables communication with the **HeartClick5** sensor module, based on the **AFE4404 analog front-end** by Texas Instruments. It supports I2C communication and allows you to access raw LED and ambient photodiode data for heart rate and SpO₂ signal extraction.

---

## 📦 Files

- `HeartClick5.h` — Class interface definitions
- `HeartClick5.cpp` — Implementation of register access and signal readout
- `HeartClick5_hal.cpp` — Optional hardware abstraction helpers (if required)

---

## 🔌 Hardware Interface

- **I2C Address**: `0x58`
- **Power**: 3.3V (recommended)
- **Pins**:
  - `SCL` → Arduino SCL
  - `SDA` → Arduino SDA
  - `GND` → Ground
  - `VCC` → 3.3V
  - Optional `RST` → Digital pin (if using software reset)

---

## 🚀 Getting Started

### 1. Clone or Copy the Files

Place `HeartClick5.h`, `HeartClick5.cpp` in your Arduino project folder.

### 2. Include and Initialize the Sensor

```cpp
#include <Wire.h>
#include "HeartClick5.h"

HeartClick5 heartSensor(0x58); // Default I2C address

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (heartSensor.begin()) {
    Serial.println("✅ HeartClick5 initialized.");
  } else {
    Serial.println("❌ Sensor not found.");
    while (1); // Halt
  }
}
```

---

## 🧠 Example: Reading SpO₂ Signal

The most relevant signal for oximetry is the **difference between LED2 and its ambient phase**, accessible via `getLed2MinusAled2Val()`.

```cpp
void loop() {
  int32_t rawSpO2 = heartSensor.getLed2MinusAled2Val();
  Serial.println(rawSpO2);
  delay(100);
}
```

---

## 🛠 API Reference

### Initialization

```cpp
HeartClick5 sensor(0x58);
sensor.begin();
```

### Signal Readouts (24-bit Registers)

```cpp
int32_t getLed2Val();
int32_t getAled2ValLed3Val();
int32_t getLed1Val();
int32_t getAled1Val();
int32_t getLed2MinusAled2Val(); // Preferred for SpO₂
int32_t getLed1MinusAled1Val(); // Preferred for HR
```

---

## 📊 SpO₂ Estimation Logic

To compute SpO₂:

1. Sample both `LED2 - ALED2` and `LED1 - ALED1` over time.
2. Calculate the AC and DC components.
3. Use the ratio-of-ratios method:

```math
R = (AC_red / DC_red) / (AC_ir / DC_ir)
SpO₂ ≈ 110 - 25 × R
```

A moving average or peak-to-peak calculation is typically used for AC, and a long-term average for DC.

---

## 📘 Datasheet & References

- 📄 [AFE4404 Datasheet (TI / MikroE)](https://download.mikroe.com/documents/datasheets/afe4404.pdf)
- 🧪 [Texas Instruments AFE4404 Product Page](https://www.ti.com/product/AFE4404)
- 📚 MikroElektronika Heart Rate 5 Click board

---

## 🧪 Advanced Usage

You can also access and configure register-level controls:

- Pulse timing
- LED current settings
- Gain settings
- TIA bandwidth
- Power modes

Use setters like `writeRegister(uint8_t reg, uint32_t val)` or expose additional API calls.

---

## 🧑‍💻 Author

Adapted by your team from MikroE’s C library to Arduino C++ for easy integration with embedded projects.

---

## 📝 License

MIT License or based on MikroElektronika SDK license if using their base source.
```

Let me know if you want this converted to PDF, added to a repo, or expanded with visuals or usage diagrams!
