#include "hal_gpio.h"

#include <stdint.h>
#include <stdbool.h>


void  led_setup()
{
  rcc_periph_clock_enable(RCC_GPIOA);
  gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
}

void buttons_setup()
{
  rcc_periph_clock_enable(RCC_GPIOA);
  gpio_mode_setup(BUTTONS_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, BUTTON1_PIN | BUTTON2_PIN);
}

bool button_read(uint16_t pin)
{
  if(gpio_get(BUTTONS_PORT, pin ) == 0)
  {
    delay_ms(20);
  
  return (gpio_get(BUTTONS_PORT, pin) == 0);
  }
  return false;
}
void led_on(void)
{
  gpio_set(LED_PORT, LED_PIN);
}
void led_off(void)
{
  gpio_clear(LED_PORT, LED_PIN);
}

//since i configured the stm32 at 96mhz and we want to make the delay
//in ms then we need to devide 96M over 1K and since the loop takes around
//4 cycles then we divide again over 4 which equals to almost 24,000
//THE DELAY IS NOT ACCURATE
void delay_ms(uint32_t count)
{
  for(uint32_t i = 0 ; i < ( count * 24000 ); i++)
  {
    __asm__("nop");
  }
}

