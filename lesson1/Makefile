CXX=g++
CC=gcc

CXXFLAGS=-g
CFLAGS=-g

SRC=movie.cpp \
	rental.cpp \
	customer.cpp
OBJ=movie.o \
	rental.o \
	customer.o

INCLUDE=.

TARGET=moviemanager

%.o:%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $< -o $@

all: $(OBJ)
	mkdir -p bin
	$(CXX) main.cpp $(OBJ) -o bin/$(TARGET)

clean: $(OBJ)
	rm -rf $(OBJ)
	rm -rf bin
