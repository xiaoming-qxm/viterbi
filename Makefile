# makefile for viterbi decoder
# type 'make' to generate excutable file

# compiler flags:
# -g     add dubugging information to the excutable file
# -Wall  turns on most, but not all, compiler warnings
CXXFLAGS = -g -Wall -std=c++11

# the build target excutable:
TARGET = viterbi_demo

all: $(TARGET)

$(TARGET): demo.o hmm.o simple_debug.o viterbi_decoder.o util.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) demo.o hmm.o simple_debug.o viterbi_decoder.o util.o

demo.o: demo.cc hmm.h util.h simple_debug.h viterbi_decoder.h
	$(CXX) $(CXXFLAGS) -c demo.cc

hmm.o: hmm.cc hmm.h
	$(CXX) $(CXXFLAGS) -c hmm.cc

simple_debug.o: simple_debug.cc simple_debug.h
	$(CXX) $(CXXFLAGS) -c simple_debug.cc

viterbi_decoder.o: viterbi_decoder.cc viterbi_decoder.h
	$(CXX) $(CXXFLAGS) -c viterbi_decoder.cc

util.o: util.cc util.h
	$(CXX) $(CXXFLAGS) -c util.cc

# To start over from scratch, type 'make clean'.
# This removes the excutable file, as well as old
# .o object files:
#
clean:
	$(RM) $(TARGET) *.o



