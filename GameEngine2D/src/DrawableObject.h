#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class DrawableObject : public virtual GameObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif
