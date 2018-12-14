//
// Created by nick on 14.12.18.
//

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H


#include <memory>

class Transformation {
private:
    static std::shared_ptr<Transformation> instance;

    Transformation();

    int pixelWidth = 0;
    int pixelHeight = 0;

public:
    /* Static access method. */
    static std::shared_ptr<Transformation> getInstance();

    void setPixelProperties(int w, int h);

    void transform(int w, int h);
};

std::shared_ptr<Transformation> Transformation::instance = nullptr;

#endif //ROADFIGHTER_TRANSFORMATION_H
