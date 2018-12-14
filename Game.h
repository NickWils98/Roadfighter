//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_GAME_H
#define ROADFIGHTER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "World.h"
#include "PlayerCarSFML.h"
#include "Car.h"
#include "PlayerCar.h"
#include "Entity.h"

class Game {
public:
    Game();

    virtual ~Game();

    void run();

    void init();

    void moveObjects();

    void handleEvent();

    void DrawBackground();
private:
    sf::RenderWindow m_window;
    std::shared_ptr<World> world;
    sf::View view;
    std::shared_ptr<PlayerCarSFML> player;
    float deltaTime = 0;
    std::vector<std::shared_ptr<sf::Texture>> textures = {};
    std::vector<sf::Sprite>backgrounds = {};
};


#endif //ROADFIGHTER_GAME_H
