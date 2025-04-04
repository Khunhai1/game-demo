#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "Renderer.h"

class Game
{
public:
    Game();
    ~Game();

    bool init(const char *title, int width, int height); // Initializes SDL, creates window, renderer, etc.
    void run();                                          // Main game loop

private:
    bool _isRunning;
    SDL_Window *_window;
    Renderer *_gameRenderer; // Renderer to handle drawing
};

#endif