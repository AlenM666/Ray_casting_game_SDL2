#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Game 
{
public: 
    Game();
    ~Game();
    void run();

private:
    SDL_Window* window = nullptr;

    const int screen_width = 1200; 
    const int screen_height = 900; 
    bool is_running;
};


