all: bashtutor

c = src/*.c src/*/*.c
h = src/*.h src/*/*.h

CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c99 -lreadline

bashtutor: $(c) $(h)
	$(CC) $(CFLAGS) $(c) -o $@
