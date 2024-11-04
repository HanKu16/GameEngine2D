#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update() = 0; 
    virtual void draw() = 0;   
};

#endif
