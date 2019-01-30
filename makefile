SRCS = $(wildcard *.c *.cc)

PROGS = $(patsubst %.c%.cc,%,$(SRCS))

CXX = g++

CC = gcc

all: $(PROGS)

%: %.cc
	$(CXX) $(CFLAGS)  -o $@ $<

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
