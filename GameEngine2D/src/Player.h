#ifndef PLAYER_H
#define PLAYER_H

#include "UpdatableObject.h"
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

class Player : public UpdatableObject, public DrawableObject {
private:
    sf::CircleShape playerShape;

public:
    Player(float x, float y);

    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif
