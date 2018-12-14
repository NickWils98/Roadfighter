//
// Created by nick on 14.12.18.
//

#include "World.h"

World::World() {
    entityList = {};
}

World::~World() {

}

void World::add(std::shared_ptr<Entity> obj) {
    entityList.push_back(obj);
    std::cout<<entityList.size();
}

void World::remove(std::shared_ptr<Entity> toDel) {
    for (int i = 0; i < entityList.size(); ++i) {
        if(entityList[i] == toDel){
            entityList.erase(entityList.begin()+i);
        }
    }
}

void World::render() {
    for(auto obj : entityList){
        obj->render();
    }
}