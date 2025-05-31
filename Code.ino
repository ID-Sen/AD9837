#include <stdint.h>
#include <stdbool.h>
#include "spi.h"

// Define the reset pin (replace with your actual pin number)
#define AD9837_RESET_PIN 5

void AD9837_Init(void) {
    GPIO_SetPinLow(AD9837_RESET_PIN);
    Delay(10);
    GPIO_SetPinHigh(AD9837_RESET_PIN);
}

void AD9837_SetFrequency(void) {
    // Control Register: Reset enabled
    SPI_Transmit(0x2100);
    // Frequency Register 0 LSB
    SPI_Transmit(0x4000);
    // Frequency Register 0 MSB
    SPI_Transmit(0x6800);
    // Phase Register 0
    SPI_Transmit(0xC000);
    // Control Register: Exit reset
    SPI_Transmit(0x2000);
}

int main(void) {
    SPI_Init();
    AD9837_Init();
    AD9837_SetFrequency();
    
    while (1) {
        // Main loop
    }

    return 0;
}
