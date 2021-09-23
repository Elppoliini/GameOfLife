#include <SFML/Graphics.hpp>

class Button
{

public:
    Button(float x, float y, float width, float height, unsigned r, unsigned g, unsigned b, std::string text);
    ~Button();
    sf::RectangleShape draw(sf::RenderWindow &window);
    bool insideButton(float x, float y);

private:
    float x, y, width, height;
    unsigned r, g, b, textSize;
    sf::FloatRect rect;
    sf::Text text;
    sf::Font font;
};
