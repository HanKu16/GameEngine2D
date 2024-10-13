#include "./Engine.h"

#include <SFML/System/Vector2.hpp>
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
    initMapping();
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

void Engine::clearToColor(int r, int g, int b){
    window.clear(sf::Color(r, g, b));
}

void Engine::setFunctionKey(std::string keyName, std::function<void()> keyFunction){
    try{
        if(keyMap.find(keyName) != keyMap.end())
            keyFunctionMap[keyName] = keyFunction;
        else
            throw std::invalid_argument("Wrong keyName declaration! No keyName like that!"); 
    }catch(std::invalid_argument &e){
        std::cerr << "Caught an invalid argument error: " << e.what() << std::endl;
    }
}

void Engine::initMapping(){
    //KEYBOARD MAPPING
    keyMap["Up"] = sf::Keyboard::Up;
    keyMap["Down"] = sf::Keyboard::Down;
    keyMap["Left"] = sf::Keyboard::Left;
    keyMap["Right"] = sf::Keyboard::Right;
    keyMap["Escape"] = sf::Keyboard::Escape;
    keyMap["Space"] = sf::Keyboard::Space;
    keyMap["Enter"] = sf::Keyboard::Enter;

    // MOUSE MAPPING
    mouseButtonsMap["Left"] = sf::Mouse::Button::Left;
    mouseButtonsMap["Right"] = sf::Mouse::Button::Right; 
}

void Engine::setFunctionMouseButton(std::string button, std::function<void()> mouseFunction){
    try{
        if(mouseButtonsMap.find(button) != mouseButtonsMap.end())
            mouseFunctionMap[button] = mouseFunction;
        else
            throw std::invalid_argument("Wrong button name declaration! No button like that!"); 
    }catch(std::invalid_argument &e){
        std::cerr << "Caught an invalid argument error: " << e.what() << std::endl;
    }
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
                    if(event.key.code == keyMap[keyIt->first])
                        keyIt->second(); 
                }
                break;

            case sf::Event::MouseButtonPressed:
                for(auto mouseIt = mouseFunctionMap.begin(); mouseIt != mouseFunctionMap.end(); mouseIt++){
                    if(event.mouseButton.button == mouseButtonsMap[mouseIt->first])
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
