//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "World.h"

class Game {
public:
    Game();

    virtual ~Game();

    void run();

    void handleEvent();

private:
    sf::RenderWindow m_window;
    std::shared_ptr<World> world;
    sf::View view;
};


#endif //ROADFIGHTER_GAME_H
