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
    init();
    //Main loop of the game
    while (m_window.isOpen()) {

        std::clock_t  beginRound = startTime;
        startTime = std::clock();
        deltaTime = startTime - beginRound;
        if(deltaTime>1.0f/20.0f){
            deltaTime= 1.0f/20.0f;
        }
        float old = player->getPosition().y;

        moveObjects();

        float newpos = player->getPosition().y;
        if(player->getPosition().y > 320){

        } else if(old>newpos){
            view.move(0, -fabsf((fabsf(old)-fabsf(newpos))));
        } else {
            view.move(0, fabsf(fabsf(old) - fabsf(newpos)));
        }
        //Render
        m_window.clear();
        m_window.setView(view);
        DrawBackground();
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

void Game::init() {
    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    tex->loadFromFile("./../pictures/car1.png");
    textures.push_back(tex);
    player = std::make_shared<PlayerCarSFML>(m_window, tex);
    world->add(player);

    std::shared_ptr<sf::Texture> backgroundTex = std::make_shared<sf::Texture>();
    backgroundTex->loadFromFile("../pictures/car_game.jpg");
    textures.push_back(backgroundTex);
    sf::Sprite background(*backgroundTex.get());
    backgrounds.push_back(background);
    background.setPosition(0 ,-431);

    std::shared_ptr<sf::Texture> backgrstart = std::make_shared<sf::Texture>();
    backgrstart->loadFromFile("../pictures/car_start.jpg");
    textures.push_back(backgrstart);
    sf::Sprite background2(*backgrstart.get());
    backgrounds.push_back(background2);
    background2.setPosition(0 ,0);
}

void Game::moveObjects() {
    std::vector<bool> input = player->getInput();
    player->MovePlayer(deltaTime, input);
    world->update();
}

void Game::DrawBackground() {
    if(player->getPosition().y>=-431){
        m_window.draw(backgrounds[1]);
        backgrounds[0].setPosition(0, -431);
        m_window.draw(backgrounds[0]);
        backgrounds[0].setPosition(0, -862);
        m_window.draw(backgrounds[0]);
    } else {
        backgrounds[0].setPosition(0, (static_cast<int>(player->getPosition().y) / 431 - 2) * 431);
        m_window.draw(backgrounds[0]);
        backgrounds[0].setPosition(0, (static_cast<int>(player->getPosition().y) / 431 - 1) * 431);
        m_window.draw(backgrounds[0]);
        backgrounds[0].setPosition(0, (static_cast<int>(player->getPosition().y) / 431) * 431);
        m_window.draw(backgrounds[0]);
        backgrounds[0].setPosition(0, (static_cast<int>(player->getPosition().y) / 431 + 1) * 431);
        m_window.draw(backgrounds[0]);
    }
}