.SUFFIXES : .cpp.o
CC = g++
CFLAGS= -g -Werror -Wall -std=c++11
TARGET = pvp_chess
LIBS = -lncurses

OBJECTS = $(wildcard *.o)


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o ../$@ $(OBJECTS) $(LIBS)

clean:
	rm $(OBJECTS) 
	rm depend_file
