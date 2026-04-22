//Custom libraries
#include "hal_uart.h"
//C libraries
#include <stdint.h>
//libopencm3 libraries
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>


#define  LED GPIO5
#define  PUSH_BUTTON GPIO6



static void clock_setup(void)
{
  rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_96MHZ]);
  rcc_periph_clock_enable(RCC_GPIOB);
}
static void gpio_setup(void)
{
  gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,LED);
  gpio_mode_setup(GPIOB, GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,PUSH_BUTTON);
}

int main(void)
{
  uart_init(9600);
  uart_send_string("UART READY \n");
  clock_setup();
  gpio_setup();
  
  while(1)
  {

    uint16_t state = gpio_get(GPIOB, PUSH_BUTTON);
    if (state == 0 )

    {
      gpio_set(GPIOB, LED);
      uart_send_string("BUTTON CLICKED\n");
    }
    else
    {
      gpio_clear(GPIOB, LED);
    }

  }
}
