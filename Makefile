.SUFFIXES : .cpp .o

CC=g++
CFLAGS= -g -Werror -Wall -std=c++11


DEPEND_FILE = depend_file
RESULT_DIR = object_file

#can be modified
DIRS = ./src \
			 ./src/piece

SRCS_DIRS = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
SRCS = $(notdir $(SRCS_DIRS))

OBJECTS = $(SRCS:%.cpp=%.o)
	
vpath %.cpp $(DIRS)
vpath %.h $(DIRS)
vpath %.o ./$(RESULT_DIR)


	
build : $(OBJECTS)	
	cd $(RESULT_DIR) && make all

Build : $(OBJECTS)

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o ./$(RESULT_DIR)/$@
	
depend:
	$(CC) -MM $(SRCS_DIRS) > ./$(RESULT_DIR)/$(DEPEND_FILE)

-include $(RESULT_DIR)/$(DEPEND_FILE)

clean:
	rm chess
	cd $(RESULT_DIR) && make clean
