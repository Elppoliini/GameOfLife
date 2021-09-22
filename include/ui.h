#include <SFML/Graphics.hpp>

class UI {

public:
    UI(unsigned n);
    ~UI();
    void run();

private:
    unsigned windowWidth, windowHeight, buttonBackgroundWidth, buttonBackgroundHeight, n;
};
