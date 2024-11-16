#pragma once

#include "../src/Point2D.h"

class GameObject{
    private:
        Point2D position;
    
    public:
        void setPosition(Point2D position);
        Point2D getPosition();
};
