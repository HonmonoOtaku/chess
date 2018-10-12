.SUFFIXES : .cpp.o
CC = g++
CFLAGS= -g -Werror -Wall -std=c++11

TARGET = chess
OBJECTS = $(wildcard *.o)


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o ../$@ $(OBJECTS)

clean:
	del $(OBJECTS) $(TARGET)
	rm depend_file
