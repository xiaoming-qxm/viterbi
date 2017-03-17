# makefile for viterbi decoder
# type 'make' to generate excutable file

# the compiler:
CC = g++

# compiler flags:
# -g     add dubugging information to the excutable file
# -Wall  turns on most, but not all, compiler warnings
CXXFLAGS = -g -Wall -std=c++11

# the build target excutable:
TARGET = viterbi_demo

all: $(TARGET)

$(TARGET): viterbi_demo.o hmm.o simple_debug.o viterbi_decoder.o util.o
	$(CC) $(CXXFLAGS) -o $(TARGET) viterbi_demo.o hmm.o simple_debug.o viterbi_decoder.o util.o

viterbi_demo.o: viterbi_demo.cc hmm.h util.h simple_debug.h viterbi_decoder.h
	$(CC) $(CXXFLAGS) -c viterbi_demo.cc

hmm.o: hmm.cpp hmm.h
	$(CC) $(CXXFLAGS) -c hmm.cc

simple_debug.o: simple_debug.cpp simple_debug.h
	$(CC) $(CXXFLAGS) -c simple_debug.cc

viterbi_decoder.o: viterbi_decoder.cpp viterbi_decoder.h
	$(CC) $(CXXFLAGS) -c viterbi_decoder.cc

util.o: util.cpp util.h
	$(CC) $(CXXFLAGS) -c util.cc

# To start over from scratch, type 'make clean'.
# This removes the excutable file, as well as old
# .o object files:
#
clean:
	$(RM) $(TARGET) *.o



