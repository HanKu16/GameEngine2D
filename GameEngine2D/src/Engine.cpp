#include "./Engine.h"
#include "Types.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

Engine *Engine::pInstance = nullptr;

Engine::Engine(){
    setWindowSettings(800, 800, Window);  
    setMaxFPS(30);
    canvas.create(windowResolution.width, windowResolution.height, sf::Color::Black);
    image.create(windowResolution.width, windowResolution.height);
}

Engine &Engine::getInstance(){
    if(pInstance == nullptr)
        pInstance = new Engine();

    return *pInstance;
}

void Engine::setWindowSettings(int width, int height, WindowStyle style){
    if(window.isOpen())
        window.close();

    windowResolution.width = width; 
    windowResolution.height = height;

    window.create(sf::VideoMode(windowResolution.width, windowResolution.height), "Engine Window", style);

}

CanvasConf Engine::getCanvasConf(){
    return CanvasConf{&canvas, windowResolution.width, windowResolution.height};
}

void Engine::setMaxFPS(int inFPS){
    window.setFramerateLimit(inFPS);
}

float Engine::getElapsedTime(){
    return clock.getElapsedTime().asSeconds();
}

void Engine::restartClock(){
    clock.restart();
}

void Engine::clearToColor(ColorRGB color){
    sf::Vector2u size = canvas.getSize();
    for (unsigned int x = 0; x < size.x; ++x) {
        for (unsigned int y = 0; y < size.y; ++y) {
            canvas.setPixel(x, y, sf::Color(color.r, color.g, color.b)); 
        }
    }
}

void Engine::setFunctionKey(Keyboard key, std::function<void()> keyFunction){
    keyFunctionMap[key] = keyFunction;
}

void Engine::setFunctionMouseButton(Mouse button, std::function<void()> mouseFunction){
    mouseFunctionMap[button] = mouseFunction;
}

MouseCords Engine::getMousePosition(){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    MouseCords mousePositionStruct;
    mousePositionStruct.x = mousePosition.x;
    mousePositionStruct.y = mousePosition.y;

    return mousePositionStruct;

}

void Engine::handleEvents(){
    sf::Event event;
    while(window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                for(auto keyIt = keyFunctionMap.begin(); keyIt != keyFunctionMap.end(); keyIt++){
                    if(event.key.code == static_cast<sf::Keyboard::Key>(keyIt->first))
                        keyIt->second(); 
                }
                break;

            case sf::Event::MouseButtonPressed:
                for(auto mouseIt = mouseFunctionMap.begin(); mouseIt != mouseFunctionMap.end(); mouseIt++){
                    if(event.mouseButton.button == static_cast<sf::Mouse::Button>(mouseIt->first))
                        mouseIt->second(); 
                }
                break;
        }
    }
}

void Engine::addToDrawablesQueue(sf::Sprite sprite){
    drawables.push_back(sprite);
}

void Engine::drawWindow(){
    window.clear();
    image.clear();

    sf::Texture canvasTexture;
    canvasTexture.loadFromImage(canvas);

    sf::Sprite canvasSprite;
    canvasSprite.setTexture(canvasTexture);

    image.draw(canvasSprite);

    for(std::vector<sf::Sprite>::iterator it = drawables.begin(); it != drawables.end(); ++it){
        image.draw(*it);
    }
    drawables.clear();

    image.display();

    sf::Sprite imageSprite;
    imageSprite.setTexture(image.getTexture());

    window.draw(imageSprite);
}

void Engine::startLoop(std::function<void()> customLoop){
    while(window.isOpen()){

        handleEvents();

        customLoop();

        drawWindow();
        window.display();
    }
}
