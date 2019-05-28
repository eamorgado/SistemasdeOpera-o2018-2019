CC = gcc                        # compiler to use

SRCS = $(wildcard *.c)
BINS = $(SRCS:%.c=%)

%: %.c
	$(CC) $< -o $@

.PHONY: clean

clean:
	-rm -rvf *.o $(BINS)

