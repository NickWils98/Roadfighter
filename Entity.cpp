//
// Created by nick on 14.12.18.
//

#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {

}

const Entity::coordinats &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const Entity::coordinats &position) {
    Entity::position = position;
}

const Entity::coordinats &Entity::getHit() const {
    return hit;
}

void Entity::setHit(float x, float y) {
    hit.x = x;
    hit.y = y;
}

void Entity::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

const Entity::coordinats &Entity::getSize() const {
    return size;
}

void Entity::setSize(float x, float y) {
    size.x = x;
    size.y = y;
}

Entity::coordinats &Entity::getSpeed() {
    return speed;
}

void Entity::setSpeed(const Entity::coordinats &speed) {
    Entity::speed = speed;
}

const Entity::coordinats &Entity::getHardness() const {
    return hardness;
}

void Entity::setHardness(const Entity::coordinats &hardness) {
    Entity::hardness = hardness;
}
