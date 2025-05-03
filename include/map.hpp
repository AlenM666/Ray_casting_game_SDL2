#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include "player.hpp"

#ifndef MAP_HPP
#define MAP_HPP


class Map
{
public:
    static const int MAP_SIZE = 8;
    static const int TILE_SIZE;

    void draw(SDL_Renderer* renderer, const Player& player) const;
    char get_tile(int row, int col)const;


private:
    const std::string map_data =
        "########"
        "# #    #"
        "# #  ###"
        "#      #"
        "##     #"
        "#  ### #"
        "#   #  #"
        "########";
};

#endif // !MAP_HPP
