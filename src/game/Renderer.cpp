#include "game/Renderer.h"
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>

Renderer::Renderer(SDL_Window *_window) : _renderer(nullptr), _backgroundColor({0, 0, 0, 255}), _textColor({255, 255, 255, 255}), _font(nullptr), _textTexture(nullptr)
{
    // Create the SDL renderer
    _renderer = SDL_CreateRenderer(_window, NULL);
    if (!_renderer)
    {
        std::cerr << "Error SDL_CreateRenderer: " << SDL_GetError() << std::endl;
    }

    // Initialize SDL_ttf
    if (!TTF_Init())
    {
        std::cerr << "Error TTF_Init: " << SDL_GetError() << std::endl;
    }

    // Load the font
    _font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 11);
    if (!_font)
    {
        std::cerr << "Error TTF_OpenFont: " << SDL_GetError() << std::endl;
    }

    // Create the text texture
    SDL_Surface *textSurface = TTF_RenderText_Blended(_font, "Hello World!", NULL, _textColor);
    if (!textSurface)
    {
        std::cerr << "Error TTF_RenderText_Solid: " << SDL_GetError() << std::endl;
    }
    else
    {
        _textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
        if (!_textTexture)
        {
            std::cerr << "Error SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        }
        // Center the text on the screen
        _helloWorldRect = {static_cast<float>(800 / 2 - textSurface->w / 2), static_cast<float>(600 / 2 - textSurface->h / 2), static_cast<float>(textSurface->w), static_cast<float>(textSurface->h)};

        SDL_DestroySurface(textSurface);
    }
}

Renderer::~Renderer()
{
    if (_renderer)
    {
        SDL_DestroyRenderer(_renderer);
    }
    _renderer = nullptr;
    if (_textTexture)
    {
        SDL_DestroyTexture(_textTexture);
    }
    _textTexture = nullptr;
    if (_font)
    {
        TTF_CloseFont(_font);
    }
    _font = nullptr;
    // Quit SDL_ttf
    TTF_Quit();
}

void Renderer::render()
{
    // Clear the screen with the background color
    SDL_SetRenderDrawColor(_renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderClear(_renderer);

    // Render the text texture
    if (_textTexture)
    {
        SDL_RenderTexture(_renderer, _textTexture, NULL, &_helloWorldRect);
    }

    // Present the renderer
    SDL_RenderPresent(_renderer);
}
