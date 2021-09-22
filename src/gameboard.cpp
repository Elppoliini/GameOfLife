#include "../include/gameboard.h"
#include <utility>

Gameboard::Gameboard(float x, float y, float width, float height, unsigned n){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->n = n;
    this->rect = sf::FloatRect(this-> x, this->y, this->width, this->height);
};

Gameboard::~Gameboard(){

};

//draw a cell to gameboard
void Gameboard::draw(sf::RenderWindow &window, Game &game){
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            if(game.getCell(x, y)) {
                float w = this->width/this->n;
                float h = this->height/this->n;
                sf::RectangleShape cell(sf::Vector2f(w, h));
                cell.setPosition(x*w, y*h);
                cell.setFillColor(sf::Color(255,155,65));
                window.draw(cell);
            }
        }
    }
};

//Check that given coordinates are inside the gameboard area
bool Gameboard::insideGameboard(float x, float y){
    return this->rect.contains(x, y);
};
    
//Get coordinates to a cell
std::pair<unsigned, unsigned> Gameboard::coordinatesToCellIndex(float x, float y){
    unsigned cellX = x * this->n / this->width;
    unsigned cellY = y * this->n / this->height;
    return std::make_pair(cellX, cellY);
};
