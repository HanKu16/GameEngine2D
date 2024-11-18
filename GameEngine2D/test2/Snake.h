#pragma once

#include "Types.h"
#include "Fruit.h"
#include <vector>

class Snake{
    private:
        bool isDead;
        int xDir;
        int yDir;
        GameCords headCords;
        std::vector<GameCords> bodyCords;

    private:
        bool isCollision();

    public:
        Snake();
        bool getIsDead();
        void setMoveDirection(int xDir, int yDir);
        bool growIfFruit(GameCords fruitCords);
        void move(Fruit &fruit);
        void draw();

};
