//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

class Entity {
public:
    Entity();

    virtual ~Entity();

    virtual void render() = 0;
    virtual void update() = 0;
    virtual bool OnCollision(std::shared_ptr<Entity> other) = 0;

    struct coordinats {
        float x = 0;
        float y = 0;
    };

    const coordinats &getPosition() const;

    const coordinats &getHit() const;

    void setHit(float x, float y);

    void setPosition(const coordinats &position);

    void setPosition(float x, float y);

    const coordinats &getSize() const;

    void setSize(float x, float y);

    coordinats &getSpeed();

    void setSpeed(const coordinats &speed);

    const coordinats &getHardness() const;

    void setHardness(const coordinats &hardness);

protected:
    coordinats position;
    coordinats speed;
    coordinats hit;
    coordinats size;
    coordinats hardness;
    float accelerator;
    float maxSpeed;


};


#endif //ROADFIGHTER_ENTITY_H
