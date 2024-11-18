#pragma once

#include "Types.h"
#include <vector>

class Fruit{
    private:
        GameCords fruitCords;
    
    private:
        bool isFruitCollision(int x, int y, std::vector<GameCords> snakeBody);

    public: 
        Fruit();
        void spawnFruit(GameCords snakeHead, std::vector<GameCords> snakeBody);
        void draw();
        GameCords getFruitCords();

};
