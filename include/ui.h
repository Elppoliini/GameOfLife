#include <SFML/Graphics.hpp>

class UI {

public:
    UI(unsigned width, unsigned height);
    ~UI();
    void run();

private:
    unsigned windowWidth, windowHeight, buttonBackgroundWidth, buttonBackgroundHeight;
};
