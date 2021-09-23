# GameOfLife

## Requirements

- SFML 2.5.1
- GCC compiler

### Installing SFML on Ubuntu

`sudo apt-get install libsfml-dev`

### Installing GCC on Ubuntu

`sudo apt install build-essential`

## Compiling

Build project by running:

`make`


## Usage

Program is runned by the following command where n is an unsigned integer that tells the game board dimensions (n*n). Command opens the GUI window:

`./build/gameoflife <n>`

User can change the state of cell to be alive or get killed by clicking the white area of game board.

