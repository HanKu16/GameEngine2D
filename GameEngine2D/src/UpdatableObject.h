#pragma once
#include "GameObject.h"

class UpdatableObject : virtual public GameObject {
    public:
        virtual ~UpdatableObject() = default;

        virtual void update(float deltaTime) = 0;
};

