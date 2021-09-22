#include <SFML/Graphics.hpp>

class Button {

public:
    Button(float x, float y, float width, float height, unsigned r, unsigned g, unsigned b);
    ~Button();
    sf::RectangleShape draw();
    bool insideButton(float x, float y);

private:
    float x, y, width, height;
    unsigned r, g, b; 
    sf::FloatRect rect;
};
