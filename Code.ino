#include <stdint.h>
#include <stdbool.h>
#include <SPI.h> // Include the Arduino SPI library

// Define the reset pin (replace with your actual pin number)
#define AD9837_RESET_PIN 5

void AD9837_Init(void) {
    pinMode(AD9837_RESET_PIN, OUTPUT); // Set the reset pin as an output
    digitalWrite(AD9837_RESET_PIN, LOW); // Set reset low
    delay(10); // Wait for 10 milliseconds
    digitalWrite(AD9837_RESET_PIN, HIGH); // Set reset high
}

void AD9837_SetFrequency(void) {
    // Control Register: Reset enabled
    SPI.transfer(0x2100);
    // Frequency Register 0 LSB
    SPI.transfer(0x4000);
    // Frequency Register 0 MSB
    SPI.transfer(0x6800);
    // Phase Register 0
    SPI.transfer(0xC000);
    // Control Register: Exit reset
    SPI.transfer(0x2000);
}

void setup() {
    SPI.begin(); // Initialize the SPI library
    AD9837_Init(); // Initialize the AD9837
    AD9837_SetFrequency(); // Set the frequency
}

void loop() {
    // Main loop (empty for now)
}
