all: bashtutor

c = src/*.c

bashtutor: $(c)
	clang -Wall $(c) -o $@