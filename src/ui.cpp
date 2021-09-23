#include "../include/ui.h"
#include "../include/button.h"
#include "../include/gameboard.h"
#include <iostream>

//Creates an object
UI::UI(unsigned n)
{
    this->windowWidth = 900;
    this->windowHeight = 600;
    this->buttonBackgroundWidth = 0.3 * this->windowWidth;
    this->buttonBackgroundHeight = this->windowHeight;
    this->n = n;
    this->font.loadFromFile("assets/ubuntu.mono.ttf");
    this->generation.setFont(this->font);
    this->generation.setCharacterSize(32);
    this->generation.setFillColor(sf::Color::Black);
};

UI::~UI(){

};

//
void UI::run()
{
    sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowHeight), "Game of Life");
    sf::Clock clock;
    Game game = Game(this->n);
    // test shape to try out the game
    game.setCell(3, 3, true);
    game.setCell(5, 3, true);
    game.setCell(5, 4, true);
    game.setCell(5, 2, true);
    game.setCell(4, 4, true);
    window.setFramerateLimit(60);
    bool startPressed = false;
    sf::RectangleShape buttonBackground(sf::Vector2f(this->buttonBackgroundWidth, this->buttonBackgroundHeight));
    buttonBackground.setFillColor(sf::Color(245, 175, 105));
    float buttonBackgroundXpos = 0.7 * this->windowWidth;
    float buttonBackgroundYpos = 0.f;
    buttonBackground.setPosition(buttonBackgroundXpos, buttonBackgroundYpos);

    float gameButtonXpos = buttonBackgroundXpos * 1.09;
    float gameButtonWidth = this->buttonBackgroundWidth * 0.6;
    float gameButtonHeight = this->buttonBackgroundHeight * 0.1;
    float startButtonYpos = buttonBackgroundYpos + 100;
    Button startButton = Button(gameButtonXpos, startButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Auto-play");
    float nextButtonYpos = buttonBackgroundYpos + 200;
    Button nextButton = Button(gameButtonXpos, nextButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Next");
    float resetButtonYpos = buttonBackgroundYpos + 300;
    Button resetButton = Button(gameButtonXpos, resetButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Reset");
    Gameboard gameboard = Gameboard(0, 0, buttonBackgroundXpos, this->windowHeight, this->n);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {

                if (startButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    startPressed = !startPressed;
                    std::cout << "START pressed\n";
                }
                else if (nextButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    std::cout << "NEXT pressed\n";
                    game.evolveOnce();
                }
                else if (resetButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    game.reset();
                    startPressed = false;
                }
                else if (gameboard.insideGameboard(event.mouseButton.x, event.mouseButton.y))
                {
                    std::pair<unsigned, unsigned> cellPos = gameboard.coordinatesToCellIndex(event.mouseButton.x, event.mouseButton.y);
                    bool state = game.getCell(cellPos.first, cellPos.second);
                    game.setCell(cellPos.first, cellPos.second, !state);
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(buttonBackground);
        std::string genInfo= "Generation: ";
        genInfo.append(std::to_string(game.getGen()));
        this->generation.setString(genInfo);
        this->generation.setPosition(buttonBackgroundXpos * 1.02, this->windowHeight - 50);
        startButton.draw(window);
        nextButton.draw(window);
        resetButton.draw(window);
        window.draw(this->generation);
        gameboard.draw(window, game);
        window.display();
        sf::Time elapsed = clock.getElapsedTime();
        if (startPressed && elapsed.asSeconds() >= 1)
        {
            clock.restart();
            game.evolveOnce();
        }
    }
};
