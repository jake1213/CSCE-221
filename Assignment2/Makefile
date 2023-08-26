CXX=g++
IDIR=$(PWD)/include
ODIR=$(PWD)/obj
SDIR=$(PWD)/src
CXXFLAGS=-O3 -std=c++11 -Wall -Werror -g -I$(IDIR)

all: $(ODIR)/1b.out $(ODIR)/2a.out $(ODIR)/2b.out $(ODIR)/3a.out $(ODIR)/3b.out $(ODIR)/4a.out $(ODIR)/4b.out $(ODIR)/7b.out $(ODIR)/8b.out $(ODIR)/9.out
$(ODIR)/1b.out: $(ODIR)/1b.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/1b.o: $(SDIR)/1b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/2a.out: $(ODIR)/2a.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/2a.o: $(SDIR)/2a.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/2b.out: $(ODIR)/2b.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/2b.o: $(SDIR)/2b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/3a.out: $(ODIR)/3a.o
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/3a.o: $(SDIR)/3a.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/3b.out: $(ODIR)/3b.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/3b.o: $(SDIR)/3b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/4a.out: $(ODIR)/4a.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/4a.o: $(SDIR)/4a.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/4b.out: $(ODIR)/4b.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/4b.o: $(SDIR)/4b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/7b.out: $(ODIR)/7b.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/7b.o: $(SDIR)/7b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/8b.out: $(ODIR)/8b.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/8b.o: $(SDIR)/8b.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/9.out: $(ODIR)/9.o 
	$(CXX) $(CXXFLAGS) -o $@ $^
$(ODIR)/9.o: $(SDIR)/9.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(ODIR)/*