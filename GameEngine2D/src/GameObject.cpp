#include "./GameObject.h"
#include "Point2D.h"


void GameObject::setPosition(Point2D position){
    this->position = position;
}

Point2D GameObject::getPosition(){
    return position;
}
