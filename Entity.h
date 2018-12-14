//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <iostream>
#include <vector>
#include <memory>

class Entity {
public:
    Entity();

    virtual ~Entity();

    virtual void render() = 0;
    virtual void update() = 0;

    struct coordinats {
        float y = 0;
        float x = 0;
    };
    coordinats position;
};


#endif //ROADFIGHTER_ENTITY_H
