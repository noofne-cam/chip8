#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct screen
{
    uint8_t *display;
};

uint8_t init_screen(struct screen *main_screen)
{
    uint8_t *display_raw = calloc(64*32, sizeof(uint8_t));
    main_screen->display = display_raw;
}
static struct screen main_screen = { 0 };

/* helper functions */
uint16_t fetch_pixel(size_t index)
{
    uint8_t width = (uint8_t)(index % 64);
    uint8_t height = (uint8_t)(index / 32);

    return (width << 8) | height;
}

bool write_pix8(uint16_t pixel_anchor, uint8_t data)
{
    uint8_t width = (pixel_anchor >> 8) & 0x00ff;
    uint8_t height = pixel_anchor & 0x00ff;
    
    size_t pixel_index = (size_t)(width + 64*height);
    bool collision = 0;
    for (size_t i = 0; i < 8; ++i)
    {
        bool bit = (data >> (7-i)) & 0x01;
        main_screen.display[pixel_index + i] ^= bit;
        if (bit && main_screen.display[pixel_index + i] == 0)
        {
            collision = 1;
        }
    }

    return collision;
}

