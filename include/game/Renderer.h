#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class Renderer
{
public:
    Renderer(SDL_Window *_window);
    ~Renderer();

    void render(); // Example of rendering other components like UI or game objects

private:
    SDL_Renderer *_renderer;
    SDL_Color _backgroundColor;
    SDL_Color _textColor;
    TTF_Font *_font;
    SDL_Texture *_textTexture;
    SDL_FRect _helloWorldRect;
};

#endif