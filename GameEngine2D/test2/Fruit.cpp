#include "Fruit.h"
#include "Types.h"
#include "../src/PrimitiveRenderer.h"
#include <vector>
#include <iostream>

Fruit::Fruit(){
    fruitCords.x = 2;
    fruitCords.y = 2;
}

bool Fruit::isFruitCollision(int x, int y, std::vector<GameCords> snakeBody){
    for(GameCords part : snakeBody){
        if(part.x == x && part.y == y)
            return true;
    }
    return false;
}

void Fruit::spawnFruit(GameCords snakeHead, std::vector<GameCords>snakeBody){
    int x, y;
    do{
        x = rand() % (GRID_SIZE - 1);
        y = rand() % (GRID_SIZE - 1);
    }while(isFruitCollision(x, y, snakeBody));

    fruitCords.x = x;
    fruitCords.y = y;

}

void Fruit::draw(){
    PrimitiveRenderer::getInstance().drawRectangle(Point2D(fruitCords.x * BLOCK_SIZE, fruitCords.y * BLOCK_SIZE),
                Point2D(fruitCords.x * BLOCK_SIZE + BLOCK_SIZE, fruitCords.y * BLOCK_SIZE),
                Point2D(fruitCords.x * BLOCK_SIZE + BLOCK_SIZE, fruitCords.y * BLOCK_SIZE + BLOCK_SIZE),
                Point2D(fruitCords.x * BLOCK_SIZE, fruitCords.y * BLOCK_SIZE + BLOCK_SIZE), ColorRGB{255, 0, 0});
        PrimitiveRenderer::getInstance().floodFill(Point2D(fruitCords.x * BLOCK_SIZE + 1, fruitCords.y * BLOCK_SIZE + 1), ColorRGB{255, 0, 0}, ColorRGB{0,0,0});
}

GameCords Fruit::getFruitCords(){
    return fruitCords;
}
