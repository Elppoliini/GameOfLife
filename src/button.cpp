#include "../include/button.h"
#include <iostream>

//Creates an object
Button::Button(float x, float y, float width, float height, unsigned r, unsigned g, unsigned b, std::string text){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
    this->rect = sf::FloatRect(this-> x, this->y, this->width, this->height);
    this->font.loadFromFile("assets/ubuntu.mono.ttf");
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(32);
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(x + 10, y+ 10);
};

Button::~Button(){

};

//
sf::RectangleShape Button::draw(sf::RenderWindow &window){
    sf::RectangleShape button(sf::Vector2f(this->width, this->height));
    button.setFillColor(sf::Color(this->r,this->g,this->b));
    button.setPosition(this->x, this->y);
    window.draw(button);
    window.draw(this->text);
    return button;
};

// check that given coordinates are inside the button area
bool Button::insideButton(float x, float y){
     return this->rect.contains(x, y);
};
