#include "../include/ui.h"
#include "../include/button.h"
#include "../include/gameboard.h"
#include <iostream>

UI::UI(unsigned n)
{
    this->windowWidth = 900;
    this->windowHeight = 600;
    this->buttonPanelWidth = 0.3 * this->windowWidth;
    this->buttonPanelHeight = this->windowHeight;
    this->n = n;
    this->font.loadFromFile("assets/ubuntu.mono.ttf");
    this->generation.setFont(this->font);
    this->generation.setCharacterSize(32);
    this->generation.setFillColor(sf::Color::Black);
};

UI::~UI(){

};

// Executes main loop and creates GUI
void UI::run()
{
    sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowHeight), "Game of Life");
    sf::Clock autoPlayClock;
    Game game = Game(this->n);
    window.setFramerateLimit(60);

    // Create a variable for auto-play
    bool autoPlayOn = false;

    // Create a display panel for buttons
    sf::RectangleShape buttonPanel(sf::Vector2f(this->buttonPanelWidth, this->buttonPanelHeight));
    buttonPanel.setFillColor(sf::Color(245, 175, 105));
    float buttonPanelXpos = 0.7 * this->windowWidth;
    float buttonPanelYpos = 0.f;
    buttonPanel.setPosition(buttonPanelXpos, buttonPanelYpos);

    // Create button components
    float gameButtonXpos = buttonPanelXpos * 1.09;
    float gameButtonWidth = this->buttonPanelWidth * 0.6;
    float gameButtonHeight = this->buttonPanelHeight * 0.1;
    float autoPlayButtonYpos = buttonPanelYpos + 100;
    Button autoPlayButton = Button(gameButtonXpos, autoPlayButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Auto-play");
    float nextButtonYpos = buttonPanelYpos + 200;
    Button nextButton = Button(gameButtonXpos, nextButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Next");
    float resetButtonYpos = buttonPanelYpos + 300;
    Button resetButton = Button(gameButtonXpos, resetButtonYpos, gameButtonWidth, gameButtonHeight, 255, 155, 65, "Reset");

    Gameboard gameboard = Gameboard(0, 0, buttonPanelXpos, this->windowHeight, this->n);

    // Main loop starts
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

                if (autoPlayButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    autoPlayOn = !autoPlayOn;
                }
                else if (nextButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    game.evolveOnce();
                }
                else if (resetButton.insideButton(event.mouseButton.x, event.mouseButton.y))
                {
                    game.reset();
                    autoPlayOn = false;
                }
                else if (gameboard.insideGameboard(event.mouseButton.x, event.mouseButton.y))
                {
                    std::pair<unsigned, unsigned> cellPos = gameboard.coordinatesToCell(event.mouseButton.x, event.mouseButton.y);
                    bool state = game.getCell(cellPos.first, cellPos.second);
                    game.setCell(cellPos.first, cellPos.second, !state);
                }
            }
        }

        // Update generation info
        std::string genInfo= "Generation: ";
        genInfo.append(std::to_string(game.getGen()));
        this->generation.setString(genInfo);
        this->generation.setPosition(buttonPanelXpos * 1.02, this->windowHeight - 50);

        // Clear window with white
        window.clear(sf::Color::White);

        // Draw all components
        window.draw(buttonPanel);
        autoPlayButton.draw(window);
        nextButton.draw(window);
        resetButton.draw(window);
        window.draw(this->generation);
        gameboard.draw(window, game);

        window.display();

        // Handle auto-play
        sf::Time elapsed = autoPlayClock.getElapsedTime();
        if (autoPlayOn && elapsed.asSeconds() >= 1)
        {
            autoPlayClock.restart();
            game.evolveOnce();
        }
    }
};
