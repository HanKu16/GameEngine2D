#include "../src/Engine.h"
#include "../src/PrimitiveRenderer.h"
#include "../src/shapes.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>


int radius = 15;
int leftClick = false;

ColorRGB colors[] = {
    {255, 0, 0},   // Red
    {0, 255, 0},   // Green
    {0, 0, 255},   // Blue
    {255, 255, 0}, // Yellow
    {0, 255, 255}, // Cyan
    {255, 0, 255}, // Magenta
    {255, 255, 255}, // White
    {0, 0, 0},     // Black
    {128, 0, 0},   // Maroon
    {0, 128, 0},   // Dark Green
    {0, 0, 128},   // Navy Blue
    {128, 128, 0}, // Olive
    {128, 0, 128}, // Purple
    {0, 128, 128}, // Teal
    {192, 192, 192}, // Silver
    {255, 165, 0}, // Orange
    {255, 20, 147} // Deep Pink
};

int colorIndex = 0;

void drawCircle(){
    MouseCords mousePos = Engine::getInstance().getMousePosition();
    if(mousePos.x > 15 && mousePos.x < 775 && mousePos.y < 755 && mousePos.y > 20){
        PrimitiveRenderer::getInstance().drawCircle(Point2D(mousePos.x, mousePos.y), radius, colors[colorIndex]);
        PrimitiveRenderer::getInstance().floodFill(Point2D(mousePos.x + radius - 1, mousePos.y), colors[colorIndex], ColorRGB{255,255,255});
    PrimitiveRenderer::getInstance().floodFill(Point2D(mousePos.x - radius + 1, mousePos.y), colors[colorIndex], ColorRGB{255,255,255});
    PrimitiveRenderer::getInstance().floodFill(Point2D(mousePos.x, mousePos.y + radius - 1), colors[colorIndex], ColorRGB{255,255,255});
    PrimitiveRenderer::getInstance().floodFill(Point2D(mousePos.x, mousePos.y - radius + 1), colors[colorIndex], ColorRGB{255,255,255});
    }
}

void setLeftClick(){
    if(leftClick)
        leftClick = false;
    else
        leftClick = true;
}

void scaleUp(){
    if(radius < 200)
        radius += 10;
}

void scaleDown(){
    if(radius > 5)
        radius -= 10;
}

void colorNext(){
    colorIndex += 1;
    if(colorIndex > sizeof(colors) / sizeof(colors[0]))
        colorIndex = 0;
}

void clear(){
    Engine::getInstance().clearToColor(ColorRGB{255,255,255}); 
}

void fillClick(){
    MouseCords mousePos = Engine::getInstance().getMousePosition();
    PrimitiveRenderer::getInstance().floodFill(Point2D(mousePos.x, mousePos.y), colors[colorIndex], ColorRGB{255,255,255});
}

void gameLoop(){
    if(leftClick)
        drawCircle();
}

int main(){
    srand(time((NULL)));
    Engine &engine = Engine::getInstance();

    engine.setMaxFPS(60);
    engine.clearToColor(ColorRGB{255,255,255});
    engine.setFunctionMouseButton(LeftClick, setLeftClick);
    engine.setFunctionMouseButton(RightClick, fillClick);
    engine.setFunctionKey(Up, scaleUp);
    engine.setFunctionKey(Down, scaleDown);
    engine.setFunctionKey(Right, colorNext);
    engine.setFunctionKey(Space, clear);

    engine.startLoop(gameLoop);
}
