#include "hal_uart.h"


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

void uart_init(uint32_t baudrate)
{
  // Enable clocks
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_USART1);

  // Configure GPIO
  gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6 | GPIO7);
  gpio_set_af(GPIOB, GPIO_AF7 ,GPIO6 | GPIO7);

  // Configure USART
  usart_set_baudrate(USART1, baudrate);
  usart_set_databits(USART1, 8);
  usart_set_stopbits(USART1, USART_STOPBITS_1);
  usart_set_mode(USART1, USART_MODE_TX_RX);
  usart_set_parity(USART1, USART_PARITY_NONE);
  usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

  // Enable USART
  usart_enable(USART1);
}

void uart_send_char(char c)
{
  usart_send_blocking(USART1, c);
}
void uart_send_string(const char *str)
{
  while(*str)
  {
    uart_send_char(*str++);
  }
}
char uart_read_char(void)
{
  return usart_recv_blocking(USART1);
}

