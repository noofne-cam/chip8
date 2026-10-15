#include <stdint.h>

struct reg 
{
    uint8_t registers[16];
    uint16_t I;
};

void init_reg(struct reg main_reg)
{
    for (size_t i = 0; i < 16; ++i) { main_reg.registers[i] = 0; }
    main_reg.I = 0;
}
static struct reg main_reg = { 0 };

/* helper functions */
uint8_t read_reg(size_t rindex)
{
    if (rindex >= 16) { /* ... */ return 0; }
    return main_reg.registers[rindex];
}
void write_reg(size_t rindex, uint8_t value)
{
    if (rindex >= 16) { /* ... */ return; }
    main_reg.registers[rindex] = value;
}

uint16_t read_I() { return main_reg.I; }
void write_I(uint16_t value) { main_reg.I = (value & 0x0fff); }