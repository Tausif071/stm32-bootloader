# STM32F103 Custom UART Bootloader

A custom bootloader built from scratch on STM32F103C8T6 (Blue Pill) 
using bare-metal C — no HAL libraries, no Arduino, pure register-level programming.

## Project Status
- [x] GPIO bare-metal — LED blink via direct register access
- [x] UART bare-metal — bidirectional serial communication
- [ ] Flash erase/write routines
- [ ] XMODEM protocol receiver
- [ ] Jump to application
- [ ] CRC verification

## Hardware Used
- STM32F103C8T6 "Blue Pill" (ARM Cortex-M3, 72MHz, 64KB flash)
- ST-Link V2 programmer
- CP2102 USB-TTL adapter

## What Makes This Different
No HAL. No Arduino. Every peripheral configured at register level:
- RCC clock enable via APB2ENR register
- GPIO configured via CRH/CRL registers
- UART configured via BRR, CR1, SR, DR registers directly

## Concepts Demonstrated
- Memory-mapped peripheral access in C
- volatile keyword for hardware registers
- Bit manipulation (|=, &=~, ^=) for register control
- Bare-metal toolchain: arm-none-eabi-gcc + STM32CubeIDE

## Memory Map Plan
| Region | Start Address | Size |
|--------|--------------|------|
| Bootloader | 0x08000000 | 16KB |
| Application | 0x08004000 | 48KB |
| RAM | 0x20000000 | 20KB |

## Tools
- IDE: STM32CubeIDE 2.1.1
- Compiler: arm-none-eabi-gcc
- Debugger: ST-Link V2 via SWD
- Serial Monitor: PuTTY at 9600 baud

## Progress Log
- Day 1: LED blink working — GPIO register config confirmed
- Day 2: UART TX working — "Hello World" printing over serial
- Day 3: UART RX working — bidirectional communication confirmed