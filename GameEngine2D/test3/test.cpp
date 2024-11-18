#include "../src/Engine.h"
#include "../src/PrimitiveRenderer.h"
#include "../src/shapes.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>


std::vector<Circle> circleList;
int radius = 15;

ColorRGB returnRandomColor(){
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;

    return ColorRGB{r,g,b};
}

void putCircleOnCanvas(){
    MouseCords mousePos = Engine::getInstance().getMousePosition();
    circleList.emplace_back(Point2D(mousePos.x, mousePos.y), radius, returnRandomColor());
}

void drawCircleList(){
    for(Circle circle : circleList)
        circle.draw();
}

void drawCircleAtMouse(){
    MouseCords mousePos = Engine::getInstance().getMousePosition();
    if(mousePos.x > 15 && mousePos.x < 775 && mousePos.y < 755 && mousePos.y > 20)
        PrimitiveRenderer::getInstance().drawCircle(Point2D(mousePos.x, mousePos.y), radius, ColorRGB{255, 0, 0});

}

void scaleUp(){
    if(radius < 200)
        radius += 10;
}

void scaleDown(){
    if(radius > 5)
        radius -= 10;
}

void gameLoop(){
    Engine::getInstance().clearToColor(ColorRGB{0,0,0});
    drawCircleAtMouse();
    drawCircleList();
}

int main(){
    srand(time((NULL)));
    Engine &engine = Engine::getInstance();

    engine.setMaxFPS(30);

    engine.setFunctionMouseButton(LeftClick, putCircleOnCanvas);
    engine.setFunctionKey(Up, scaleUp);
    engine.setFunctionKey(Down, scaleDown);

    engine.startLoop(gameLoop);
}
