#include <stdint.h>
#include <stdlib.h>

struct screen
{
    uint8_t *display;
};

uint8_t init_screen(struct screen *main_screen)
{
    uint8_t *display_raw = calloc(64*32, sizeof(uint8_t));
    main_screen->display = display_raw;
}

