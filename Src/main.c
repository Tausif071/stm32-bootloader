volatile unsigned int *RCC_APB2ENR  = (unsigned int*)0x40021018;
volatile unsigned int *GPIOA_CRH    = (unsigned int*)0x40010804;
volatile unsigned int *USART1_SR    = (unsigned int*)0x40013800;
volatile unsigned int *USART1_DR    = (unsigned int*)0x40013804;
volatile unsigned int *USART1_BRR   = (unsigned int*)0x40013808;
volatile unsigned int *USART1_CR1   = (unsigned int*)0x4001380C;

void uart_send_char(char c) {
    // Wait until transmit buffer is empty (TXE bit = bit 7)
    while(!(*USART1_SR & (1 << 7)));
    // Write character to data register
    *USART1_DR = c;
}

void uart_print(char *str) {
    while(*str) {
        uart_send_char(*str);
        str++;
    }
}

void delay(volatile unsigned int n) {
    while(n--);
}

int main() {
    // Enable clock for GPIOA and USART1
    *RCC_APB2ENR |= (1<<2) | (1<<14);

    // Configure PA9 as alternate function push-pull output
    *GPIOA_CRH &= ~(0xF << 4);
    *GPIOA_CRH |=  (0xB << 4);

    // Set baud rate 9600 at 8MHz HSI clock
    // BRR = 8000000 / 9600 = 833 = 0x341
    *USART1_BRR = 0x341;

    // Enable USART1 and TX
    *USART1_CR1 = (1<<13) | (1<<3);

    uart_print("Hello World\r\n");

    while(1) {
        uart_print("STM32 Bootloader Learning\r\n");
        delay(1000000);
    }

    return 0;
}
