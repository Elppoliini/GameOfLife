#include "../include/button.h"

//Creates an object
Button::Button(float x, float y, float width, float height, unsigned r, unsigned g, unsigned b){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
    this->rect = sf::FloatRect(this-> x, this->y, this->width, this->height);
};

Button::~Button(){

};

//
sf::RectangleShape Button::draw(){
    sf::RectangleShape button(sf::Vector2f(this->width, this->height));
    button.setFillColor(sf::Color(this->r,this->g,this->b));
    button.setPosition(this->x, this->y);
    return button;
};

// check that given coordinates are inside the button area
bool Button::insideButton(float x, float y){
     return this->rect.contains(x, y);
};
