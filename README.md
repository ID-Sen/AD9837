# AD9837

MCLK used- 16MHz, if increased the calculation will chang, changing Frequency Register 0 LSB & Frequency Register 0 MSB.
The sequence involves entering reset mode, entering data into the Freq0 register, and exiting reset mode.

Connect the SPI pins (MOSI, MISO, SCK, CS) from the microcontroller to the corresponding pins on the AD9837.
Connect the reset pin to a GPIO pin on the microcontroller.
Provide power and ground connections to the AD9837.

0x2100  Control Register
0x4000 Frequency Register 0 LSB
0x6800 Frequency Register 0 MSB
0xC000 Phase Register 0
0x2000 Exit Reset
