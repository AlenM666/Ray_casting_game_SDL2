#pragma once 
#include <SDL2/SDL.h>
#include "map.hpp"


#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player
{
public:
    Player(int screen_width);

    void handle_input();
    void update(const Map& map);

    double get_x() const;
    double get_y() const;
    double get_angle() const;

private:
    double x, y, angle;
    bool moving_forward;
};

#endif // !PLAYER_HPP
