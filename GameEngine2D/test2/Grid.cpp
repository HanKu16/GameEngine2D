#include "Fruit.h"
#include "Types.h"
#include "../src/PrimitiveRenderer.h"
#include <vector>
#include <iostream>

bool Fruit::isFruitCollision(int x, int y, std::vector<GameCords> snakeBody){
    for(GameCords part : snakeBody){
        if(part.x == x && part.y == y)
            return false;
    }
    return true;
}

void Fruit::spawnFruit(GameCords snakeHead, std::vector<GameCords>snakeBody){
    int x, y;
    do{
        x = rand() % (GRID_SIZE - 1);
        y = rand() % (GRID_SIZE - 1);
    }while(isFruitCollision(x, y, snakeBody));

    gameBoard[y][x] = 1;

    PrimitiveRenderer::getInstance().drawRectangle(Point2D(x * BLOCK_SIZE, y * BLOCK_SIZE),
                Point2D(x * BLOCK_SIZE + BLOCK_SIZE, y * BLOCK_SIZE),
                Point2D(x * BLOCK_SIZE + BLOCK_SIZE, y * BLOCK_SIZE + BLOCK_SIZE),
                Point2D(x * BLOCK_SIZE, y * BLOCK_SIZE + BLOCK_SIZE), ColorRGB{255, 0, 0});
        PrimitiveRenderer::getInstance().floodFill(Point2D(x * BLOCK_SIZE + 1, y * BLOCK_SIZE + 1), ColorRGB{255, 0, 0}, ColorRGB{0,0,0});
}

void Fruit::setGameBoardCellZero(int x, int y){
    
}

