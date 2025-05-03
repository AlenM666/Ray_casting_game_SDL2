#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
// #include "./../include/player.hpp"
#include "./../include/map.hpp"


const int Map::TILE_SIZE = 480 / Map::MAP_SIZE;

void Map::draw(SDL_Renderer* renderer, const Player& player) const 
{
    // iterate over map
    for (int i = 0; i < MAP_SIZE; ++i) 
    {
        for (int j = 0; j < MAP_SIZE; ++j) 
        {
            //draw map
            SDL_Rect tile_rect = { j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1 };
            // calculate square
            if ( map_data[i * MAP_SIZE + j] == '#')
            {
                SDL_SetRenderDrawColor(renderer, 191, 191, 191, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 65, 65, 65, 255);
            }
            SDL_RenderFillRect(renderer, &tile_rect);

        }
    }

    // TODO: Draw player
    SDL_SetRenderDrawColor(renderer, 162, 0, 255, 255);
    SDL_Rect player_circle = { static_cast<int>(player.get_x()) - 6, static_cast<int>(player.get_y()) - 6, 12, 12 };
    SDL_RenderFillRect(renderer, &player_circle);
}

char Map::get_tile(int row, int col) const
{
    if (row < 0 || row >= MAP_SIZE || col < 0 || col >= MAP_SIZE)
        return '#';
    return map_data[row * MAP_SIZE + col];
}
