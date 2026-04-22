#pragma once

#include <stdint.h>

// Init UART 
void uart_init(uint32_t baudrate);

// Send one byte
void uart_send_char(char c);

// Send one string
void uart_send_string(const char *str);

// Receive one byte
char uart_read_char(void);

