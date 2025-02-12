#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_VERM = 28;
const int BTN_PIN_VERDE = 26;
const int LED_PIN_VERM = 4;
const int LED_PIN_VERDE = 6;

int main() {
  stdio_init_all();
  gpio_init(LED_PIN_VERM);
  gpio_init(LED_PIN_VERDE);
  gpio_set_dir(LED_PIN_VERM, GPIO_OUT);
  gpio_set_dir(LED_PIN_VERDE,GPIO_OUT);

  gpio_init(BTN_PIN_VERDE);
  gpio_init(BTN_PIN_VERM);
  gpio_set_dir(BTN_PIN_VERDE, GPIO_IN);
  gpio_set_dir(BTN_PIN_VERM, GPIO_IN);  
  gpio_pull_up(BTN_PIN_VERDE);
  gpio_pull_up(BTN_PIN_VERM);

  int i = 0;
  int j = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_VERDE)) {
      if (i == 0){
        i = 1;
        gpio_put(LED_PIN_VERDE,i);
      } else{
        i = 0;
        gpio_put(LED_PIN_VERDE,i);
      }
      while (!gpio_get(BTN_PIN_VERDE)) {
    };
  }

  if (!gpio_get(BTN_PIN_VERM)){
    if (j == 0){
      j = 1;
      gpio_put(LED_PIN_VERM,j);
    } else{
      j = 0;
      gpio_put(LED_PIN_VERM,j);
    }
    while (!gpio_get(BTN_PIN_VERM)){
    };
  }
}
}
