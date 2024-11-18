#include "../src/Engine.h"
#include "../src/PrimitiveRenderer.h"
#include "Fruit.h"
#include "Snake.h"
#include <cstdlib>
#include <ctime>


Fruit fruit = Fruit();
Snake snake = Snake();

void gameLoop(){
    snake.move(fruit);
    if(snake.getIsDead())
        exit(0); 

    snake.draw();
    fruit.draw();
}

void moveUp(){
    snake.setMoveDirection(0, -1);
}

void moveDown(){
    snake.setMoveDirection(0, 1);
}

void moveLeft(){
    snake.setMoveDirection(-1, 0);
}

void moveRight(){
    snake.setMoveDirection(1, 0);
}

int main(){
    srand(time(NULL));
    Engine &engine = Engine::getInstance();

    engine.setMaxFPS(8);

    engine.setFunctionKey(Up, moveUp);
    engine.setFunctionKey(Down, moveDown);
    engine.setFunctionKey(Left, moveLeft);
    engine.setFunctionKey(Right, moveRight);

    engine.startLoop(gameLoop);
}
