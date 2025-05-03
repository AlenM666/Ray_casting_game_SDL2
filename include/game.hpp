#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include "map.hpp"
#include "ray_caster.hpp"
#include "player.hpp"

class Game 
{
public: 
    Game();
    ~Game();
    void run();
    void creation_error();

private:
    void handle_events();
    void update();
    void render();
    void clean();

    SDL_Window* window = nullptr;
    TTF_Font* font = nullptr;
    SDL_Renderer* renderer= nullptr;

    const int screen_width = 960; 
    const int screen_height = 480; 
    bool is_running;

    Player player;
    Map map;
    Ray_Caster ray_caster;

    // unasignd 32bit int for fps
    Uint32 last_tick;
};


