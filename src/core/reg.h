#pragma once

#include <stdint.h>

uint8_t read_reg(size_t rindex);
void write_reg(size_t rindex, uint8_t value);

uint16_t read_I();
void write_I(uint16_t value);

uint16_t read_pc();
void write_pc(uint16_t value);