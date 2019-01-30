SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

CXX = g++

CC = gcc

all: $(PROGS)

%: %.cc
	$(CXX) $(CFLAGS)  -o $@ $<

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
