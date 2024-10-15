#include "./Engine.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <stdexcept>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>


Engine *Engine::pInstance = nullptr;

Engine::Engine(){
    setWindowSettings(800, 600, "window"); 
    setMaxFPS(30);
}

Engine &Engine::getInstance(){
    if(pInstance == nullptr)
        pInstance = new Engine();

    return *pInstance;
}

void Engine::setWindowSettings(int width, int height, std::string style){
    try{
        if(window.isOpen())
            window.close();

        windowResolution[0] = width; 
        windowResolution[1] = height;

        if(style == "window")
            windowStyle = sf::Style::Default;
        else if(style == "fullscreen")
            windowStyle = sf::Style::Fullscreen;
        else 
            throw std::invalid_argument("Wrong window style declaration!");

        window.create(sf::VideoMode(windowResolution[0], windowResolution[1]), "Engine Window", windowStyle);

    }catch(std::invalid_argument &e){
        std::cerr << "Caught an invalid argument error: " << e.what() << std::endl;
    }
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

void Engine::clearToColor(Color color){
    window.clear(sf::Color(color.r, color.g, color.b));
}

void Engine::setFunctionKey(Keyboard key, std::function<void()> keyFunction){
    keyFunctionMap[key] = keyFunction;
}

void Engine::setFunctionMouseButton(Mouse button, std::function<void()> mouseFunction){
    mouseFunctionMap[button] = mouseFunction;
}

mouseCords Engine::getMousePosition(){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    mouseCords mousePositionStruct;
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

void Engine::startLoop(std::function<void()> customLoop){
    while(window.isOpen()){

        handleEvents();

        customLoop();

        window.display();
    }
}
