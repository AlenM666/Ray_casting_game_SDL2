#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "./../include/game.hpp"
#include "./../include/player.hpp"
#include "./../include/map.hpp"

Game::Game()
: player(screen_width), ray_caster(screen_width, screen_height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
    {
        std::cerr << "SDL init failed! " << SDL_GetError() << std::endl;
        is_running = false;
        return;
    }

    window = SDL_CreateWindow("Ray_Casting_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, 0 );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("/usr/share/fonts/Adwaita/AdwaitaMono-Regular.ttf", 24);

    creation_error();
    last_tick = SDL_GetTicks();

};

Game::~Game()
{
    clean();
}

void Game::run()
{
    while ( is_running )
    {
        handle_events();
        update();
        render();
        SDL_Delay(1000 / 30);
    }
}

void Game::handle_events()
{
    SDL_Event event;
    while ( SDL_PollEvent(&event))
    {
        if ( event.type == SDL_QUIT) is_running = false;
    }
    player.handle_input();
}


void Game::update()
{
    player.update(map);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //3D simple backgournd
    SDL_Rect sky = { screen_height, 0, screen_width / 2, screen_height / 2 };
    SDL_RenderFillRect(renderer, &sky);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_Rect floor = { screen_height, screen_height / 2, screen_width / 2, screen_height / 2 };
    SDL_RenderFillRect(renderer, &floor);

    map.draw(renderer, player);
    ray_caster.cast(renderer,player,map);


    //FPS counter
    Uint32 now = SDL_GetTicks();
    float delta_time = (now - last_tick) / 1000.0f;
    last_tick = now;
    int fps = int(1.0f / delta_time);

    SDL_Color white = {255, 255, 255};
    SDL_Surface* fps_surface = TTF_RenderText_Solid(font, std::to_string(fps).c_str(), white);
    SDL_Texture* fps_texture = SDL_CreateTextureFromSurface(renderer, fps_surface);
    SDL_Rect fps_rect = { screen_width / 2, 0, fps_surface->w, fps_surface->h };
    SDL_RenderCopy(renderer, fps_texture, NULL, &fps_rect);
    SDL_FreeSurface(fps_surface);
    SDL_DestroyTexture(fps_texture);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    if (font) TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void Game::creation_error()
{
    if ( !window )
    {
        std::cerr << "Window creatino failed!" << SDL_GetError() << std::endl;
    }
    if ( !renderer ) {
        std::cerr << "Renderer creation failed!" << SDL_GetError() << std::endl;
    }
    if ( !font )
    {
        std::cerr << "Font creation failed!" << SDL_GetError() << std::endl;
    }
}




