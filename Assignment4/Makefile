CXX=g++
IDIR=$(PWD)/include
CXXFLAGS=-O3 -std=c++17 -Wall -Werror -g -I$(IDIR)

all: ./obj/heapsort.out ./obj/dijkstra.out

./obj/heapsort.out: ./obj/heapsort.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/heapsort.o: ./src/heapsort.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $< 
./obj/dijkstra.out: ./obj/dijkstra.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/dijkstra.o: ./src/dijkstra.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o