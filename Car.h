//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_CAR_H
#define ROADFIGHTER_CAR_H


#include "Entity.h"

class Car : public Entity {
public:
    Car();

    virtual ~Car();

    virtual void render() = 0;
    virtual void update() = 0;
    virtual bool OnCollision(std::shared_ptr<Entity> other) = 0;
};


#endif //ROADFIGHTER_CAR_H
