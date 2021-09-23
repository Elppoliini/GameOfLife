#include <stdio.h>
#include "../include/game.h"
#include "../include/ui.h"
#include <time.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stdexcept>

int main(int argc, char **argv)
{
    unsigned n;

    if (argc != 2)
    {
        std::cout << "Invalid amount of arguments" << std::endl;
        return 1;
    }
    try
    {
        n = std::stol(argv[1]);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid argument. Argument must be unsigned positive integer" << std::endl;
        return 1;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Integer value is out of range" << std::endl;
        return 1;
    }
    if (n == 0)
    {
        std::cout << "Integer value is not positive" << std::endl;
        return 1;
    }
    UI userInterface = UI(n);
    userInterface.run();

    return 0;
}
