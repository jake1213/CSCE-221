CXX=g++
IDIR=$(PWD)/include
CXXFLAGS=-O3 -std=c++17 -Wall -Werror -g -I$(IDIR)

all: ./obj/nodeinfo.out ./obj/MergeVector.out

./obj/nodeinfo.out: ./obj/nodeinfo.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/nodeinfo.o: ./src/NodeInfo.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<
./obj/MergeVector.out: ./obj/MergeVector.o
	$(CXX) $(CXXFLAGS) -o $@ $^
./obj/MergeVector.o: ./src/MergeVector.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o