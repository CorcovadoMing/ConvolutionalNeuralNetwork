.PHONY: test clean

CPP=g++
CC=gcc
CXXFLAGS=-O3
SRC_FOLDER=src
TEST_FOLDER=test
MAIN_FILE=main.c
EXE=cnn

all:
	@$(CC) $(CXXFLAGS) $(SRC_FOLDER)/*.c $(MAIN_FILE) -o $(EXE)

test:
	@$(CPP) $(CXXFLAGS) $(SRC_FOLDER)/*.c $(TEST_FOLDER)/*.cpp -o $(EXE) && ./$(EXE)

clean:
	@rm ./$(EXE)

