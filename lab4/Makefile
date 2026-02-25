CC = gcc
CFLAGS = -Wall -Wextra -g

TARGETS = sjf rr

all: $(TARGETS)

sjf: sjf.c process.h
	$(CC) $(CFLAGS) sjf.c -o sjf

rr: rr.c process.h
	$(CC) $(CFLAGS) rr.c -o rr

clean:
	rm -f $(TARGETS)
