CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)

all: $(ODIR)/w1.out $(ODIR)/w2.out $(ODIR)/w3.out $(ODIR)/w4.out $(ODIR)/nodeinfo.out
$(ODIR)/w1.out: $(ODIR)/w1.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/w1.o: $(SDIR)/w1.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/w2.out: $(ODIR)/w2.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/w2.o: $(SDIR)/w2.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/w3.out: $(ODIR)/w3.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/w3.o: $(SDIR)/w3.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/w4.out: $(ODIR)/w4.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/w4.o: $(SDIR)/w4.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/nodeinfo.out: $(ODIR)/nodeinfo.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/nodeinfo.o: $(SDIR)/NodeInfo.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(ODIR)/*