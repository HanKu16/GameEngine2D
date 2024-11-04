#include "Player.h"

Player::Player(float x, float y) : playerShape(20.0f) {  
    playerShape.setPosition(x, y);
    playerShape.setFillColor(sf::Color::Blue);
}

void Player::update() {
        const float moveSpeed = 5.0f;

  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerShape.move(-moveSpeed, 0);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerShape.move(moveSpeed, 0);   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        playerShape.move(0, -moveSpeed);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        playerShape.move(0, moveSpeed);   
    }
}


void Player::draw(sf::RenderWindow& window) {
    window.draw(playerShape);
}
