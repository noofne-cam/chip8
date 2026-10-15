#pragma once

#include <stdint.h>

uint8_t read_delay();
void write_delay(uint8_t value);
void write_sound(uint8_t value);

void dec_delay();
void dec_sound();