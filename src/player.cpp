#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <cmath>
#include "./../include/player.hpp"


Player::Player(int screen_widht)
{
    x = ( screen_widht / 2 ) / 2.0;
    y = ( screen_widht / 2 ) / 2.0;
    angle = M_PI;
    moving_forward = true;
}


void Player::handle_input()
{
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_LEFT])
        angle -= 0.1;
    if (keystates[SDL_SCANCODE_RIGHT])
        angle += 0.1;
    if (keystates[SDL_SCANCODE_UP])
        moving_forward = true;
    if (keystates[SDL_SCANCODE_DOWN])
        moving_forward = false;
}

void Player::update(const Map& map)
{
    double move_step = 5;
    double next_x = x + ( moving_forward ? -1 : 1 ) * sin(angle) * move_step;
    double next_y = y + ( moving_forward ? 1 : -1 ) * cos(angle) * move_step;

    int col = int ( next_x / Map::TILE_SIZE );
    int row = int ( next_y / Map::TILE_SIZE );

    if ( map.get_tile( row,  col) != '#')
    {
        x = next_x;
        y = next_y;
    }
}

double Player::get_x() const { return x; }
double Player::get_y() const { return y; }
double Player::get_angle() const { return angle; }
