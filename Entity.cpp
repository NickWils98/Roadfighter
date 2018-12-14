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
