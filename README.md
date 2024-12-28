# LCD Clock Arduino Project

## Overview

This Arduino project demonstrates how to create a simple digital clock using an LCD screen and an RTC (Real-Time Clock) module. The project features:

- Displaying the current time in 12-hour format with AM/PM on a 16x2 LCD.
- Automatically setting the RTC time to the compile time if not running.
- An additional custom message displayed on the second line of the LCD.

## Components Required

- Arduino (e.g., Uno, Mega, Nano)
- 16x2 LCD screen
- RTC module (e.g., DS1307 or similar)
- Jumper wires
- Breadboard (optional)

## Circuit Diagram

### Pin Connections

| **LCD Pins**         | **Arduino Pins** |
| -------------------- | ---------------- |
| RS (Register Select) | 12               |
| EN (Enable)          | 11               |
| D4                   | 5                |
| D5                   | 4                |
| D6                   | 3                |
| D7                   | 2                |

| **RTC Pins** | **Arduino Pins** |
| ------------ | ---------------- |
| SDA          | A4               |
| SCL          | A5               |

## Installation

1. Install the required Arduino libraries:

   - [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)
   - [RTClib](https://github.com/adafruit/RTClib)

   You can install these libraries through the Arduino IDE Library Manager.

2. Connect the components as described in the circuit diagram.
3. Upload the provided code to your Arduino board.

## How It Works

1. **RTC Initialization**:

   - The program checks if the RTC module is connected and functional.
   - If the RTC is not running, it sets the time to the compile time.

2. **LCD Display**:

   - The first line of the LCD displays the current time in `HH:MM:SS AM/PM` format.
   - The second line shows a custom message (`NoFoxTuGiv` by default).

3. **Time Formatting**:
   - The time is fetched from the RTC module and converted to a 12-hour format with an AM/PM indicator.

## Customization

- **Custom Message**: Replace the text `NoFoxTuGiv` in the `loop()` function with your desired message to display on the second line of the LCD.

## Notes

- The `delay(1000)` function ensures the time updates every second.
- Ensure that your RTC module has a functioning battery to maintain time when the Arduino is powered off.

## Troubleshooting

- **RTC not detected**:

  - Ensure the SDA and SCL pins are connected correctly.
  - Check if the RTC module is powered and has a functional battery.

- **Incorrect time**:
  - Double-check the RTC initialization code.
  - Verify the battery in the RTC module.

## License

This project is open-source and available for use and modification under the MIT License.
