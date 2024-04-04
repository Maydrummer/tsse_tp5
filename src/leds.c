#include "leds.h"

#define LED_OFFSET 1
#define BIT_HIGH   1
#define SET_ZERO   0x00
#define ON_ALL     0xFF
#define HIGH       1
#define LOW        0

static uint16_t * puntero;

static uint16_t led_to_mask(int led) {
    return (BIT_HIGH << (led - LED_OFFSET));
}

void leds_init(uint16_t * puerto) {
    puntero = puerto;
    *puerto = SET_ZERO;
}

void leds_turn_on(int led) {
    *puntero |= led_to_mask(led);
}

void leds_turn_off(int led) {
    *puntero &= ~(led_to_mask(led));
}

void leds_all_on(uint16_t * puerto) {
    *puntero = ON_ALL;
}

int led_state(int led) {
    int res;
    uint16_t estado = *puntero;
    estado &= led_to_mask(led);

    if (estado != 0) {
        res = HIGH; // led bit activo
    } else {
        res = LOW; // bit desactivado
    }
    return res;
}
