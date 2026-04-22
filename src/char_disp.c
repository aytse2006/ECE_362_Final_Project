#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/dma.h"
#include "hardware/gpio.h"
#include "chardisp.h"

void cd_init() {

    // fill in
    sleep_ms(1);
    send_spi_cmd(spi1, 0x2c);
    sleep_ms(0.04);
    send_spi_cmd(spi1, 0x0c);
    sleep_ms(0.04);
    send_spi_cmd(spi1, 0x01);
    sleep_ms(2);
    send_spi_cmd(spi1, 0x06);
    sleep_ms(0.04);
}

void cd_display1(const char *str) {

    // fill in
    send_spi_cmd(spi1, 1ul << 1);

    for(int a=0; a<16; a++) {
        send_spi_data(spi1, str[a]);
    }
}

void cd_display2(const char *str) {

    // fill in
    send_spi_cmd(spi1, ((1ul << 6) |(1ul << 7)));

    for(int b=0; b<16; b++) {
        send_spi_data(spi1, str[b]);
    }
}

void send_spi_cmd(spi_inst_t* spi, uint16_t value) {

    // fill in
    while(spi_get_hw(spi)->sr & SPI_SSPCPSR_BITS) {
        tight_loop_contents();
    }

    spi_get_hw(spi)->dr = value;
}


void send_spi_data(spi_inst_t* spi, uint16_t value) {

    // fill in
    send_spi_cmd(spi, value | 0x100);
}



