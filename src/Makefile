CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c2x

MMU = -Immu mmu/mmu.c
CORE = -Icore core/reg.c core/ppu.c core/timer.c

.run:
	$(CC) $(CFLAGS) -o out $(MMU) $(CORE) main.c
	./out
	del out.exe