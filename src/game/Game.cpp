#include "game/Game.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

Game::Game() : _isRunning(false), _window(nullptr), _gameRenderer(nullptr) {}

Game::~Game()
{
    if (_gameRenderer)
    {
        delete _gameRenderer;
    }
    if (_window)
    {
        SDL_DestroyWindow(_window);
    }
    TTF_Quit();
    SDL_Quit();
}

bool Game::init(const char *title, int width, int height)
{
    // Init video
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "Error SDL_Init: " << SDL_GetError() << std::endl;
        return false;
    }

    // Init ttf
    if (TTF_Init() < 0)
    {
        std::cerr << "Erreur TTF_Init: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Create window
    _window = SDL_CreateWindow(title, width, height, 0);
    if (!_window)
    {
        std::cerr << "Error SDL_CreateWindow: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Create game renderer
    _gameRenderer = new Renderer(_window);

    _isRunning = true;
    return true;
}

void Game::run()
{
    SDL_Event event;
    while (_isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                _isRunning = false;
            }
        }

        // Render the game
        _gameRenderer->render();
    }
}