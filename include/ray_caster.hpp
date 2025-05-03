#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <cmath>
#include "player.hpp"
#include "map.hpp"


class Ray_Caster
{

public:
    Ray_Caster(int screen_width, int screen_height);

    void cast(SDL_Renderer* renderer, const Player& player, const Map& map);

private:
    int screen_width, screen_height;
    const int casted_rays = 160;
    const double fov = M_PI / 3;
    const double half_fov = fov / 2;
    const int max_depth;
    const double scale;
    const double step_angle;

};

