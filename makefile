SRC_DIR = ./src
INC_DIR = ./include
BUILD_DIR = ./build
EXECUTABLE_FILE_NAME = gameoflife
LIBS = -lsfml-graphics -lsfml-window -lsfml-system


all: main.o game.o ui.o
	g++ -o $(BUILD_DIR)/$(EXECUTABLE_FILE_NAME) $(BUILD_DIR)/*.o $(LIBS)

main.o: $(SRC_DIR)/main.cpp 
	g++ -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

game.o: $(SRC_DIR)/game.cpp
	g++ -c $(SRC_DIR)/game.cpp -o $(BUILD_DIR)/game.o

ui.o: $(SRC_DIR)/ui.cpp
	g++ -c $(SRC_DIR)/ui.cpp -o $(BUILD_DIR)/ui.o
