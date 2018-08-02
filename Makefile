.SUFFIXES : .cpp .o

CC=g++
CFLAGS=-std=c++11


DEPEND_FILE = depend_file
RESULT_DIR = result_file

#can be modified
DIRS = ./src/chess_board \
	   ./src/chess_pieces \
	   ./src/error_handle \
	   ./src/main \
	   ./RESULT_DIR
	

SRCS_DIRS = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
SRCS = $(notdir $(SRCS_DIRS))

OBJECTS = $(SRCS:%.cpp=%.o)

vpath %.cpp $(DIRS)
vpath %.h $(DIRS)
vpath %.o ./result


	
build : $(OBJECTS)	
	cd $(RESULT_DIR) && make all

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $@
	mv $@ $(RESULT_DIR)
	
depend:
	$(CC) -MM $(SRCS_DIRS) > $(DEPEND_FILE)
	mv $(DEPEND_FILE) $(RESULT_DIR)

-include $(RESULT_DIR)/$(DEPEND_FILE)

clean:
	cd $(RESULT_DIR) && make clean
