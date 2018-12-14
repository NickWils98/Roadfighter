//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_COLLIDER_H
#define ROADFIGHTER_COLLIDER_H


#include "Entity.h"

class Collider : public Entity {
public:
    explicit Collider(std::shared_ptr<Entity> obj);
    ~Collider();

    void Move(float dx, float dy){object->setPosition(object->getPosition().x+dx, object->getPosition().y+dy);};

    bool CheckCollision(Collider other, float push);
    coordinats GetPosition(){return object->getPosition();};
    coordinats GetHalfSize();
    virtual void render();

    virtual void update();

    virtual bool OnCollision(std::shared_ptr<Entity> other);

private:
    std::shared_ptr<Entity> object;

};


#endif //ROADFIGHTER_COLLIDER_H
