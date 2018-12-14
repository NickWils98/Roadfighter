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
    position.x = 200;
    position.y = 300;
    accelerator = 3;
    maxSpeed = 10;
    hardness.x = 0.5;
    hardness.y = 0.5;
}

PlayerCarSFML::~PlayerCarSFML() {

}

void PlayerCarSFML::render() {
    window.draw(body);
}

void PlayerCarSFML::update() {
    body.setPosition(position.x, position.y);
}

std::vector<bool> PlayerCarSFML::getInput() {
    std::vector<bool> input = {};

    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    return input;
}

