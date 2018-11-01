.SUFFIXES : .cpp.o
CC = g++
CFLAGS= -g -Werror -Wall -std=c++11
TARGET = pvp_chess

OBJECTS = $(wildcard *.o)


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o ../$@ $(OBJECTS)

clean:
	rm $(OBJECTS) 
	rm depend_file
