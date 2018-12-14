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
