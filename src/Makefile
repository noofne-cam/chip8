CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c2x

MMU = -Immu mmu/mmu.c

.run:
	$(CC) $(CFLAGS) -o out $(MMU) main.c
	./out
	del out.exe