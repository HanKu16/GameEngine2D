#include "./Engine.h"

#include <iostream>
#include <stdexcept>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>


Engine *Engine::pInstance = nullptr;

Engine::Engine(){
    setWindowStyle("window"); 
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
        std::cerr << "Caught a invalid argument error: " << e.what() << std::endl;
    }
}

void Engine::buildWindow(int width, int height){
    window.create(sf::VideoMode(width, height), "Engine Window", windowStyle);  
}

void Engine::startLoop(std::function<void()> customLoop){
    while(window.isOpen()){

        customLoop();

        window.display();
    }
}
