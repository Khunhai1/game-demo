#include <iostream>
#include "game/Game.h"

int main()
{
    try
    {
        // Create the game instance
        Game game = Game();
        game.init("Hello World - SDL3", 800, 600);

        // Run the game loop
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}