#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual ~ShapeObject() = default;

    virtual void draw() const override = 0;
    virtual void translate(const Point2D& offset) override = 0; 
    virtual void rotate(float angle) override = 0;
    virtual void scale(float factor) override = 0;
};

