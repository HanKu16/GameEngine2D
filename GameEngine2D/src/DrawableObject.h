#pragma once
#include "GameObject.h"

class DrawableObject : virtual public GameObject {
    public:
        virtual ~DrawableObject() = default;

        virtual void draw() const = 0;
};

