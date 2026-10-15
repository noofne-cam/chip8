#include <stdint.h>
#include <stdlib.h>

struct mmunit
{
    /* NOTE: first 512 bytes (0x0000-0x0200) unused by program */
    uint8_t *memory;
};

struct stack
{
    uint8_t *stack;
    uint8_t cursor;
};

void init_memory(struct mmunit *main_memory, struct stack *main_stack)
{
    uint8_t *main_memory_raw = calloc(0xffff, sizeof(uint8_t));
    main_memory->memory = main_memory_raw;

    uint8_t *main_stack_raw = calloc(64, sizeof(uint8_t));
    main_stack->stack = main_stack_raw;
    main_stack->cursor = 0;
}
static struct mmunit main_memory = { 0 };
static struct stack  main_stack  = { 0 };

/* helper functions */
uint8_t read_memory(uint16_t index)
{
    return main_memory.memory[index];
}
void write_memory(uint16_t index, uint8_t value)
{
    main_memory.memory[index] = value;
}

void push_stack(uint8_t value)
{
    main_stack.stack[main_stack.cursor] = value;
    main_stack.cursor = (main_stack.cursor + 1) & 0x40;
}
void pop_stack()
{
    main_stack.cursor = (main_stack.cursor - 1) & 0x40;
    main_stack.stack[main_stack.cursor] = 0;
}