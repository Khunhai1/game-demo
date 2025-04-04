#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

int main() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Initialisation de SDL TTF
    if (TTF_Init() < 0) {
        std::cerr << "Erreur TTF_Init: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Création de la fenêtre SDL
    SDL_Window* window = SDL_CreateWindow("Hello World - SDL3", 800, 600, 0);
    if (!window) {
        std::cerr << "Erreur SDL_CreateWindow: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Erreur SDL_CreateRenderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Charger la police
    TTF_Font* font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 24); // Remplacer le chemin par celui de votre police
    if (!font) {
        std::cerr << "Erreur TTF_OpenFont: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Créer une couleur pour le texte
    SDL_Color color = {255, 255, 255, 255}; // Blanc

    // Créer une surface pour le texte
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello World", 0, color);
    if (!textSurface) {
        std::cerr << "Erreur TTF_RenderText_Solid: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Créer une texture à partir de la surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_DestroySurface(textSurface);  // On peut maintenant libérer la surface
    if (!textTexture) {
        std::cerr << "Erreur SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    // Définir la position du texte
    SDL_FRect textRect = {100, 100, 400, 100};  // Positionner le texte à (100, 100)

    // Boucle principale
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Nettoyer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Noir
        SDL_RenderClear(renderer);

        // Rendre le texte
        SDL_RenderTexture(renderer, textTexture, NULL, &textRect);

        // Présenter la scène
        SDL_RenderPresent(renderer);
    }

    // Nettoyage avant de quitter
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quitter SDL et TTF
    TTF_Quit();
    SDL_Quit();

    return 0;
}