CPP=g++
CPPFLAGS=-Wall 
LIBS=-lpthread -lrt
PROGRAM_NAME=Server
SOURCE_FILES=Server.cpp

$(PROGRAM_NAME): $(SOURCE_FILES) 
	$(CPP) $^ -o $@ $(LIBS)
	./$(PROGRAM_NAME)
	
start:
	./$(PROGRAM_NAME) 