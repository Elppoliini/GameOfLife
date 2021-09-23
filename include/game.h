#include <vector>

class Game
{

public:
    Game(unsigned n);
    ~Game();
    void evolveOnce();
    void evolveNTimes(unsigned n);
    bool getCell(unsigned x, unsigned y);
    void setCell(unsigned x, unsigned y, bool value);
    unsigned neighbourCount(unsigned x, unsigned y);
    void printBoard();
    void initBoardRandomly();
    void reset();

private:
    unsigned int n, generation;
    bool cellAlive;
    std::vector<bool> gameboard;
};
