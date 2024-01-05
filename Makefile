CFLAGS:=-Wall -Wextra -std=c99 -O2

all: vector

vector: vector.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f vector

.PHONY: clean
