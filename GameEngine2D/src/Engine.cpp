#include "./Engine.h"

#include <iostream>
#include <stdexcept>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>


Engine *Engine::pInstance = nullptr;

Engine::Engine(){
    setWindowStyle("window"); 

    keyMap["Up"] = sf::Keyboard::Up;
    keyMap["Down"] = sf::Keyboard::Down;
    keyMap["Left"] = sf::Keyboard::Left;
    keyMap["Right"] = sf::Keyboard::Right;
    keyMap["Escape"] = sf::Keyboard::Escape;
    keyMap["Space"] = sf::Keyboard::Space;
    keyMap["Enter"] = sf::Keyboard::Enter;
}

Engine &Engine::getInstance(){
    if(pInstance == nullptr)
        pInstance = new Engine();

    return *pInstance;
}

void Engine::setWindowStyle(std::string style){
    try{
        if(style == "window")
            windowStyle = sf::Style::Default;
        else if(style == "fullscreen")
            windowStyle = sf::Style::Fullscreen;
        else 
            throw std::invalid_argument("Wrong window style declaration!");
    }catch(std::invalid_argument &e){
        std::cerr << "Caught an invalid argument error: " << e.what() << std::endl;
    }
}

void Engine::buildWindow(int width, int height){
    window.create(sf::VideoMode(width, height), "Engine Window", windowStyle);  
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
