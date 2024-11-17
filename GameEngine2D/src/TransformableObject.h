#pragma once
#include "GameObject.h"

class TransformableObject : virtual public GameObject {
public:
    virtual ~TransformableObject() = default;

    virtual void translate(const Point2D& offset) = 0;
    virtual void rotate(float angle) = 0; 
    virtual void scale(float factor) = 0;
};

