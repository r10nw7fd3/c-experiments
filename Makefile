CFLAGS:=-Wall -Wextra -std=c99 -O2

all: templates_vector

templates_vector: templates_vector.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f templates_vector

.PHONY: all clean
