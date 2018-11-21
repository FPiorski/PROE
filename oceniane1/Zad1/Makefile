all: main

.PHONY: clean

CC = $(CXX)
CXXFLAGS  = -std=c++11 -Wall -Wextra

release: CXXFLAGS += -O2
release: main

debug: CXXFLAGS += -g -O0
debug: main

main: main.o class.o

main.o: main.cpp class.h

class.o: class.cpp class.h

clean:
	rm -f *.o main
