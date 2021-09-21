#include "../include/game.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//All functions that use coordinates assume that they are within bounds
//0 <= x <= n-1 and 0 <= y <= n-1

//Creates an object with a gameboard that is initialized to be empty
Game::Game(unsigned int n) {
    vector<bool> v(n*n, false);
    this->gameboard = v;
    this->n = n;
    this->generation = 0;
};

Game::~Game() {

};

// Updates cell status when a generation passes
void Game::evolveOnce() {
        vector<bool> copy = this->gameboard;

        for (int x = 0; x < this->n; x++) {
            for (int y = 0; y < this->n; y++) {
                int neighbours = this->neighbourCount(x, y);
                bool alive = this->getCell(x, y);
                if (alive && (neighbours < 2 || neighbours > 3)) {
                    copy.at(x + y*this->n) = false;
                }
                if (alive && (neighbours == 2 || neighbours == 3)) {
                    copy.at(x + y*this->n) = true;
                }
                if (!alive && neighbours == 3) {
                    copy.at(x + y*this->n) = true;
                }
            }
        }
        this->gameboard = copy;
        this->generation++;
};

void Game::evolveNTimes(unsigned n) {
    for(int i = 0; i < n; i++) {
        this->evolveOnce();
    }
};

// return cell location
bool Game::getCell(unsigned x, unsigned y){
    return this->gameboard.at(x + y*this->n);
};

//set a value to a certain cell
void Game::setCell(unsigned x, unsigned y, bool value) {
    this->gameboard.at(x + y*this->n) = value;
};

//Check how many neighbours a cell has by checking the cell surroundings
unsigned Game::neighbourCount(unsigned x, unsigned y) {
    int neighbours = 0;
    for (int xOffset = -1; xOffset <= 1; xOffset++) {
        bool cellOutsideXBounds = xOffset + x < 0 || xOffset + x >= this->n;
        if (cellOutsideXBounds) {
            continue;
        }
        for (int yOffset = -1; yOffset <= 1; yOffset++) {
            bool cellOutsideYBounds = yOffset + y < 0 || yOffset + y >= this->n;
            if (cellOutsideYBounds) {
                continue;
            }
            bool currentCell = yOffset == 0 && xOffset == 0;
            if (currentCell) { 
                continue;
            }
            bool neighbourCellAlive = this->getCell(x + xOffset, y + yOffset);
            if (neighbourCellAlive) {
                neighbours++;
            }
        }
    }
    return neighbours;
};

//prints current board
void Game::printBoard() {
    for(unsigned y = 0; y < this->n; y++) {
        for(unsigned x = 0; x < this->n; x++) {
            if(this->getCell(x, y)) cout << "1";
            else cout << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
};


// randomly chooses cells from board to put them alive
void Game::initBoardRandomly() {
    int x = 0;
    srand((unsigned)time( NULL ));
    
    while (x < this->n) {
        int y = 0;
        while (y < this->n) {
            if ((float) rand()/RAND_MAX < 0.2) {
                this->setCell(x, y, true);
            }
            y++;
        }
        x++;
    }
};



