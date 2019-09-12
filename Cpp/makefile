SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))

CFLAGS = -g

CC = g++

all: $(PROGS)

%: %.cc
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
