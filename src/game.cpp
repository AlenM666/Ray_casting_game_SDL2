#include "./../include/game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL init failed! " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("Ray_Casting_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_FULLSCREEN);
};





