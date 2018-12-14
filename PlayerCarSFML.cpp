//
// Created by nick on 14.12.18.
//

#include "PlayerCarSFML.h"

PlayerCarSFML::PlayerCarSFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex)
    : window(w)
{
    body.setTexture(tex.get());
    body.setPosition(200,300);
    sf::Vector2f s = sf::Vector2f(20,35);
    body.setSize(s);
    body.setOrigin(s/2.0f);

}

PlayerCarSFML::~PlayerCarSFML() {

}

void PlayerCarSFML::render() {
    window.draw(body);
}
