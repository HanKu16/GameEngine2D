#include "../src/Engine.h"
#include "../src/PrimitiveRenderer.h"
#include "../src/BitmapObject.h"
#include "../src/shapes.h"

#include <iostream>
#include <unistd.h>


void customLoop(){
    sleep(1);
    float elapsedTime = Engine::getInstance().getElapsedTime();
    if(elapsedTime > 5.0f){
        puts("WTFF!!!!");
        Engine::getInstance().restartClock();
    }
    std::cout << Engine::getInstance().getMousePosition().x << " " << Engine::getInstance().getMousePosition().y << std::endl;

    ColorRGB red = { 255, 0, 0 };
    ColorRGB green = { 0, 255, 0 };
    ColorRGB blue = { 0, 0, 255 };

    PrimitiveRenderer &primitiveRenderer = PrimitiveRenderer::getInstance(); 

    primitiveRenderer.drawRectangle(Point2D(100, 100), Point2D(200, 100), 
        Point2D(400, 500), Point2D(100, 500), green);


    primitiveRenderer.drawTriangle(Point2D(100, 635), 
       Point2D(360, 255), Point2D(740, 525), blue);

    primitiveRenderer.drawCircle(Point2D(400, 400), 60, ColorRGB{150,240,0});
    Circle circle = Circle(Point2D(400, 400), 60, ColorRGB{150,240,0});
    circle.rotate(30);
    circle.scale(2.5);
    circle.draw();  


    primitiveRenderer.floodFill(Point2D(400, 400), ColorRGB{150,240,0}, ColorRGB{0, 0, 0});

    primitiveRenderer.drawEllipse(Point2D(300, 300), 100, 160, ColorRGB{243, 123, 32});

}

void keyUpTest(){
    puts("Key up pressed!");
}

void rightMouseTest(){
    puts("Right button pressed!");
}

int main(){
    Engine &eng = Engine::getInstance();
    
    BitmapObject bitmap = BitmapObject();
    std::string spritePath = "./sprite.jpg"; 
    bitmap.loadBitmap(spritePath, 200, 200);

    eng.setFunctionKey(Up, keyUpTest);
    eng.setFunctionMouseButton(RightClick, rightMouseTest);

    eng.startLoop(customLoop);

    return 0;
}
