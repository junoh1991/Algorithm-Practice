SRCS = $(wildcard *.cc)

PROGS = $(patsubst %.cc,%,$(SRCS))

CXX = g++

CC = gcc

all: $(PROGS)

%: %.cc
	$(CXX) $(CFLAGS)  -o $@ $<


clean:
	rm -f $(PROGS)
