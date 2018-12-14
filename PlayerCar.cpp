//
// Created by nick on 14.12.18.
//

#include "PlayerCar.h"

PlayerCar::PlayerCar() {}

PlayerCar::~PlayerCar() {

}

void PlayerCar::MovePlayer(float deltaTime, std::vector<bool> input) {
    if(!input[0] and !input[1]){
        if (speed.x>1){
            speed.x -= deltaTime*10;
        }
        else if (speed.x<-1){
            speed.x+=deltaTime*10;
        }
        else{
            speed.x = 0;
        }
    }
    if(!input[2] and !input[3]){
        if (speed.y >0.001){
            speed.y-=deltaTime*3;
        }
        else if (speed.y<-1){
            speed.y +=deltaTime*3;
        }
        else{
            speed.y = 0;
        }
    }
    if(input[0]){
        if(speed.x>0){
            speed.x -= accelerator*deltaTime*20;
        }else {
            speed.x -= accelerator*deltaTime;
        }
        if(-maxSpeed>speed.x){
                speed.x = -maxSpeed;
        }
    }
    if(input[1]){
        if(speed.x<0){
            speed.x+= accelerator*deltaTime*20;
        }else {
            speed.x += accelerator*deltaTime;
        }
        if(maxSpeed<speed.x){
            speed.x = maxSpeed;
        }
    }
    if(fabsf(speed.y>maxSpeed)){

        speed.y +=deltaTime*3;
    }
    if(input[2]){
        if(speed.y>0){
            speed.y -= accelerator*deltaTime*20;
        }else {
            if(fabsf(speed.y)>maxSpeed){

                speed.y +=deltaTime*3;
            } else{

                speed.y -= accelerator*deltaTime;
            }
        }
    }
    if(input[3]) {
        if(speed.y<0){
            speed.y += accelerator*deltaTime*20;
        }else {
            speed.y += accelerator*deltaTime;
        }
        if (maxSpeed < speed.y) {
            speed.y = maxSpeed;
        }
    }
    position.x += speed.x;
    position.y += speed.y;
    //std::cout<<speed.x<<"     "<<speed.y<<"    "<<deltaTime<<std::endl;

}

bool PlayerCar::OnCollision(std::shared_ptr<Entity> other) {
    coordinats direction = other->getHit();
    coordinats& sp = other->getSpeed();
    const coordinats hard = other->getHardness();
    if(direction.x < 0.0f){
        //Collision on the left.
        speed.x = speed.x*hard.x;
    } else if(direction.x > 0.0f){
        //Collision on the right.
        speed.x = speed.x*hard.x;
    }
    if(direction.y < 0.0f){
        //Collision on the top.
        float diff = speed.y+sp.y;
        if(hardness.y<hard.y) {
            speed.y = diff *(hard.y-hardness.y)/2;
            sp.y = diff/2;
        } else if(hardness.y> hard.y) {
            sp.y = diff *(hardness.y-hard.y)/2;
            speed.y = diff/2;
        } else{
            speed.y = diff /2;
            sp.y = diff*0.9/2;
        }



    } else if(direction.y > 0.0f){
        //Collision on the bottom.
        float diff = speed.y+sp.y;
        if(hardness.y>hard.y) {
            speed.y = diff *(hard.y-hardness.y)/2;
            sp.y = diff/2;
        } else if(hardness.y< hard.y) {
            sp.y = diff *(hardness.y-hard.y)/2;
            speed.y = diff/2;
        } else{
            speed.y = diff *0.9/2;
            sp.y = diff/2;
        }
    }
    return false;
}
