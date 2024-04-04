
#include "unity.h"
#include "leds.h"

static uint16_t leds_virtuales;
static const int LED = 3;

void setUp(void) // funcion que se ejecuta primero
{
    leds_init(&leds_virtuales);
}

void test_todos_leds_apagados_al_init_driver(void) {
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

// CON TODOS LOS LEDS APAGADOS PRENDER EL LED 3 Y
// VERIFICAR QUE EFECTIVAMENTE EL BIT 2 SE PONE EN 1
// Y EL RESTO PERMANECE EN 0

void test_prender_un_led(void) {
    leds_turn_on(LED);
    TEST_ASSERT_BIT_HIGH(LED - 1, leds_virtuales);
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

// apagar un led prendido y ver que efectivamente
// se apaga y que el resto no cambie

void test_apagar_un_led(void) {
    leds_turn_on(LED);
    leds_turn_off(LED);
    TEST_ASSERT_BIT_LOW(LED - 1, leds_virtuales);
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

// test prender todos los leds
void test_prender_todos(void) {
    leds_all_on(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0xFF, leds_virtuales);
}

// test consultar el estado de un led que este previamente encendido

void test_consultar_estado_led_prendido(void) {
    leds_turn_on(LED);
    TEST_ASSERT_EQUAL_INT(1, led_state(LED));
}
