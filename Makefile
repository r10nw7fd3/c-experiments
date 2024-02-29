CFLAGS:=-Wall -Wextra -std=c99 -O2

OUT:=templates_vector oop_point

all: $(OUT)

templates_%: templates_%.c
	$(CC) $(CFLAGS) -o $@ $<

oop_%: oop_%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OUT)

.PHONY: all clean
