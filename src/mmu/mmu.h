#pragma once

#include <stdint.h>
uint8_t read_memory(uint16_t index);
void write_memory(uint16_t index, uint8_t value);