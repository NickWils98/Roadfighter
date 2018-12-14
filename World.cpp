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

void World::update() {
    for(auto obj : entityList){
        obj->update();
    }
}

void World::Collision() {
    if(!entityList.empty()) {
        for (int i = 0; i < entityList.size() - 1; i++) {
            for (int j = 0; j < entityList.size(); j++) {
                if (i != j) {
                    Collider col(entityList[i]);
                    Collider col2(entityList[j]);
                    if(col.CheckCollision(col2, 1.0f)){
                        bool del = entityList[i]->OnCollision(entityList[j]);
                        if(del){
                            remove(entityList[j]);
                        }
                    }
                }
            }
        }
    }
}

bool World::OnCollision(std::shared_ptr<Entity> other) {
    return false;
}
