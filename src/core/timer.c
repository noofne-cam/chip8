#include <stdint.h>

struct timer 
{
    uint8_t sound;
    uint8_t delay;
};

static struct timer main_timer = { 0 };

/* helper */
uint8_t read_delay() { return main_timer.delay; }
void write_delay(uint8_t value) { main_timer.delay = value; }
void write_sound(uint8_t value) { main_timer.sound = value; }

void dec_delay() { main_timer.delay--; }
void dec_sound() { main_timer.sound--; }