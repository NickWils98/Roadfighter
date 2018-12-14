//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H


#include "Car.h"

class PlayerCar : public Car {
public:
    PlayerCar();

    virtual ~PlayerCar();

    virtual void render() = 0;
};


#endif //ROADFIGHTER_PLAYERCAR_H
