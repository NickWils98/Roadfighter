//
// Created by nick on 14.12.18.
//

#include "Game.h"

Game::Game()
        :   m_window    (sf::VideoMode(514, 431), "ROADFIGHTER",  sf::Style::Close | sf::Style::Resize),
            view(m_window.getDefaultView()) {

    m_window.setFramerateLimit(60);
    world = std::make_shared<World>();
}

    Game::~Game() {

}

void Game::run() {

    std::clock_t  startTime = std::clock();
    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    tex->loadFromFile("./../pictures/car1.png");
    textures.push_back(tex);
    player = std::make_shared<PlayerCarSFML>(m_window, tex);
    world->add(player);
    //Main loop of the game
    while (m_window.isOpen()) {

        //Render
        m_window.clear();
        m_window.setView(view);
        world->render();
        m_window.display();

        //Handle window events
        handleEvent();
    }
}


void Game::handleEvent() {
    sf::Event evnt;

    while (m_window.pollEvent(evnt)) {
        switch (evnt.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                break;
            default:
                break;

        }
    }
}