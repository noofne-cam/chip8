#pragma once

#include <stdint.h>

uint16_t fetch_pixel(size_t index);
bool write_pix8(uint16_t pixel_anchor, uint8_t data);
void clear_screen();