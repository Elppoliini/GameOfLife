SRC_DIR = ./src
INC_DIR = ./include
BUILD_DIR = ./build
EXECUTABLE_FILE_NAME = gameoflife


all:
	g++ -o $(BUILD_DIR)/$(EXECUTABLE_FILE_NAME) $(SRC_DIR)/*.cpp $(INC_DIR)/*.h
