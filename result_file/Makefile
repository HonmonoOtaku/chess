.SUFFIXES : .cpp.o
CC = g++
CFLAGS=-std=c++11

TARGET = out
OBJECTS = $(wildcard *.o)


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $(CFLAGS) $@ $(OBJECTS)
	mv $(TARGET) ../

clean:
	rm $(OBJECTS) $(TARGET)
	rm depend_file
