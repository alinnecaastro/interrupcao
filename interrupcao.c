#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pio_config.h"
#include "hardware/pwm.h"
#include "pico/bootrom.h"
#include "ws2818b.pio.h"
#include "numeros.c"
#include "definicoes.h"

bool debounce_active = false;

#define LED_COUNT 25       // Quantidade de LEDs na matriz
#define DEBOUNCE_DELAY 100 // Tempo de debounce em milissegundos

// Variáveis globais
volatile uint32_t contador = 0;
volatile bool flag_button_a = false;
volatile bool flag_button_b = false;
volatile uint32_t last_interrupt_time_a = 0;
volatile uint32_t last_interrupt_time_b = 0;



// --- INTERRUPÇÃO E DEBOUNCE --- //
// Esta função de callback é chamada sempre que há uma borda de queda em qualquer botão.
void gpio_callback(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    
    // Se o botão A foi pressionado:
    if(gpio == BUTTON_PIN_A && (events & GPIO_IRQ_EDGE_FALL)) {
        if((current_time - last_interrupt_time_a) > DEBOUNCE_DELAY) {
            flag_button_a = true;
            last_interrupt_time_a = current_time;
        }
    }
    // Se o botão B foi pressionado:
    else if(gpio == BUTTON_PIN_B && (events & GPIO_IRQ_EDGE_FALL)) {
        if((current_time - last_interrupt_time_b) > DEBOUNCE_DELAY) {
            flag_button_b = true;
            last_interrupt_time_b = current_time;
        }
    }
}



int main() {
    stdio_init_all();
    npInit(MATRIX_LED_PIN);

    // Configuração do LED vermelho
    gpio_init(GPIO_PIN_RED);
    gpio_set_dir(GPIO_PIN_RED, GPIO_OUT);

    // Configuração dos botões com pull-up interno
    gpio_init(BUTTON_PIN_A);
    gpio_set_dir(BUTTON_PIN_A, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_A);

    gpio_init(BUTTON_PIN_B);
    gpio_set_dir(BUTTON_PIN_B, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_B);

    // Configura as interrupções para ambos os botões, usando a mesma callback.
    gpio_set_irq_enabled_with_callback(BUTTON_PIN_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    gpio_set_irq_enabled(BUTTON_PIN_B, GPIO_IRQ_EDGE_FALL, true);

    printf("Sistema iniciado...\n");
    npClear();

    // Loop principal: verifica as flags geradas pelas interrupções e atualiza o display.
    while (true) {
        led_vermelho();
        if(flag_button_a) {
            contador++;
            if(contador > 9)
                contador = 0;
            mostrar_numero((uint8_t)contador);
            flag_button_a = false;
        }
        if(flag_button_b) {
            if(contador == 0)
                contador = 9;
            else
                contador--;
            mostrar_numero((uint8_t)contador);
            flag_button_b = false;
        }
        // Evita uso excessivo da CPU
        tight_loop_contents();
    }

    return 0;
}