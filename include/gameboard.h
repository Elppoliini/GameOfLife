#include "../include/game.h"
#include <SFML/Graphics.hpp>
#include <utility>

class Gameboard {

public:
    Gameboard(float x, float y, float width, float height, unsigned n);
    ~Gameboard();
    void draw(sf::RenderWindow &window, Game &game);
    bool insideGameboard(float x, float y);
    std::pair<unsigned, unsigned>  coordinatesToCellIndex(float x, float y);
    
private:
    float x, y, width, height;
    unsigned n;
    sf::FloatRect rect;
};
