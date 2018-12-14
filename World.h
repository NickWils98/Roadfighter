//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include "Entity.h"

class World : public Entity {
public:
    World();

    virtual ~World();

    void add(std::shared_ptr<Entity> obj);
    void remove(std::shared_ptr<Entity> toDel);
    void render();
private:
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;
};


#endif //ROADFIGHTER_WORLD_H
