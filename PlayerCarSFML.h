//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_PLAYERCARSFML_H
#define ROADFIGHTER_PLAYERCARSFML_H


#include <SFML/Graphics.hpp>
#include "PlayerCar.h"

class PlayerCarSFML : public PlayerCar {
public:
    PlayerCarSFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex);

    virtual ~PlayerCarSFML();

    void render() override ;

    void update() override ;

    std::vector<bool> getInput();

private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
};


#endif //ROADFIGHTER_PLAYERCARSFML_H
