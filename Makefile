all: bashtutor

c = src/*.c src/*/*.c
h = src/*.h src/*/*.h

CC = clang
CFLAGS = -Wall -Wextra -pedantic

bashtutor: $(c) $(h)
	$(CC) $(CFLAGS) $(c) -o $@