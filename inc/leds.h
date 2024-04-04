#include <stdint.h>

void leds_init(uint16_t * puerto);

void leds_turn_on(int led);

void leds_turn_off(int led);

void leds_all_on(uint16_t * puerto);

int led_state(int led);
