//
// Created by nick on 14.12.18.
//

#include "Transformation.h"

Transformation::Transformation() {

}
std::shared_ptr<Transformation> Transformation::getInstance()
{
    if (instance == nullptr)
    {
        instance = std::shared_ptr<Transformation>(new Transformation);
    }

    return instance;
}


void Transformation::setPixelProperties(int w, int h) {
    pixelWidth = w;
    pixelHeight = h;
}

void Transformation::transform(int w, int h) {

}

