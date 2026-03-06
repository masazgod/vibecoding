CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

all: paint

paint: main.c
	$(CC) $(CFLAGS) main.c -o paint $(LDFLAGS)

clean:
	rm -f paint
