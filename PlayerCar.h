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
    virtual void update() = 0;
    virtual std::vector<bool> getInput() = 0;

    void MovePlayer(float deltaTime, std::vector<bool> input);
};


#endif //ROADFIGHTER_PLAYERCAR_H
