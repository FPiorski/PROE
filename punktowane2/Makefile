all: main

.PHONY: clean release debug

CC = $(CXX)
CXXFLAGS  = -std=c++11 -Wall -Wextra

release: CXXFLAGS += -O2
release: main

debug: CXXFLAGS += -g -O0
debug: main

main: main.o complex.o

main.o: main.cpp complex.h

comeplex.o: complex.cpp comeplex.h

clean:
	rm -f *.o