#include "Snake.h"
#include "Fruit.h"
#include "../src/PrimitiveRenderer.h"
#include "Types.h"

Snake::Snake(){
    headCords.x = 11;
    headCords.y = 12;
    xDir = -1;
    yDir = 0;
}

void Snake::setMoveDirection(int xDir, int yDir){
    this->xDir = xDir;
    this->yDir = yDir;
}

bool Snake::isCollision(){
    if(headCords.x < 0 || headCords.y < 0 || headCords.x > GRID_SIZE - 2 || headCords.y > GRID_SIZE - 1)
        return true;
    for(size_t part = 0; part < bodyCords.size(); ++part){
        if(headCords.x == bodyCords[part].x &&
                headCords.y == bodyCords[part].y)
            return true;
    }

    return false;
}

bool Snake::growIfFruit(GameCords fruitCords){
    if(headCords.x == fruitCords.x && headCords.y == fruitCords.y){
        bodyCords.push_back(headCords);
        return true;
    }
    return false;
}

void Snake::move(Fruit &fruit){
    for(int part = bodyCords.size(); part > 0; --part) {
        bodyCords[part] = bodyCords[part - 1];
    }
    if(!bodyCords.empty()) 
        bodyCords[0] = headCords;

    headCords.x += xDir;
    headCords.y += yDir;
    if(isCollision()){
        isDead = true;
    }
    if(growIfFruit(fruit.getFruitCords()))
        fruit.spawnFruit(headCords, bodyCords);
}

bool Snake::getIsDead(){
    return isDead;
}

void Snake::draw(){
    PrimitiveRenderer::getInstance().drawRectangle(Point2D(headCords.x * BLOCK_SIZE, headCords.y * BLOCK_SIZE),
            Point2D(headCords.x * BLOCK_SIZE + BLOCK_SIZE, headCords.y * BLOCK_SIZE),
            Point2D(headCords.x * BLOCK_SIZE + BLOCK_SIZE, headCords.y * BLOCK_SIZE + BLOCK_SIZE),
            Point2D(headCords.x * BLOCK_SIZE, headCords.y * BLOCK_SIZE + BLOCK_SIZE), ColorRGB{255, 255, 255});
    PrimitiveRenderer::getInstance().floodFill(Point2D(headCords.x * BLOCK_SIZE + 1, headCords.y * BLOCK_SIZE + 1), ColorRGB{255, 255, 255}, ColorRGB{0,0,0});

    for(size_t part = 0; part < bodyCords.size(); ++part){
        PrimitiveRenderer::getInstance().drawRectangle(Point2D(bodyCords[part].x * BLOCK_SIZE, bodyCords[part].y * BLOCK_SIZE),
                    Point2D(bodyCords[part].x * BLOCK_SIZE + BLOCK_SIZE, bodyCords[part].y * BLOCK_SIZE),
                    Point2D(bodyCords[part].x * BLOCK_SIZE + BLOCK_SIZE, bodyCords[part].y * BLOCK_SIZE + BLOCK_SIZE),
                    Point2D(bodyCords[part].x * BLOCK_SIZE, bodyCords[part].y * BLOCK_SIZE + BLOCK_SIZE), ColorRGB{255, 255, 255});
            PrimitiveRenderer::getInstance().floodFill(Point2D(bodyCords[part].x * BLOCK_SIZE + 1, bodyCords[part].y * BLOCK_SIZE + 1), ColorRGB{255, 255, 255}, ColorRGB{0,0,0});
    }
}
