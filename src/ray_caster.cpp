#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <cmath>
#include <filesystem>
#include "./../include/map.hpp"
#include "./../include/ray_caster.hpp"


Ray_Caster::Ray_Caster(int sw, int sh)
: screen_width(sw), screen_height(sh), max_depth(Map::MAP_SIZE * Map::TILE_SIZE),
scale((screen_width / 2.0) / casted_rays),
step_angle(fov / casted_rays) {}


void Ray_Caster::cast(SDL_Renderer* renderer, const Player& player, const Map& map)
{
    double angle = player.get_angle() - half_fov;
    for ( int ray = 0; ray < casted_rays; ++ray)
    {
        for ( int depth = 1; depth < max_depth; ++depth)
        {
            double target_x = player.get_x() - sin(angle) * depth;
            double target_y = player.get_y() - cos(angle) * depth;

            int col = int( target_x / Map::TILE_SIZE );
            int row = int( target_y / Map::TILE_SIZE );

            if ( map.get_tile(row, col) == '#' )
            {
                double fixed_depth = depth * cos(player.get_angle() - angle );
                int wall_height = int( 21000 / fixed_depth );
                if ( wall_height > screen_height ) wall_height = screen_height;
                Uint8 c = 255 / ( 1 + depth * depth * 0.0001);

                SDL_SetRenderDrawColor(renderer, c, c, c, 255);
                SDL_Rect wall = {
                    screen_height + ray * (int)scale,
                    (screen_height / 2) - wall_height / 2,
                    (int)scale,
                    wall_height
                };
                SDL_RenderFillRect(renderer, &wall);
                break;
            }
        }
        angle+=step_angle;
    }
}
