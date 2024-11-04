#ifndef SHAPEOBJECT_H
#define SHAPEOBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factor) = 0;
};

#endif
