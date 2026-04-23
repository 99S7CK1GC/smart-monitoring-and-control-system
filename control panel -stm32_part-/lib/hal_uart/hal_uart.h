#pragma once

#include <stdint.h>

// Init UART 
void uart_init(uint32_t baudrate);

// Send one byte
void print_char(char c);

// Send one string
void print_text(const char *str);

// Receive one byte
char read_char(void);

