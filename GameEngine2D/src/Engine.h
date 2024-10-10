#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <functional>
#include <string>


class Engine{ 
    private:
        sf::RenderWindow window;        
        unsigned int windowStyle;

    public:
        Engine();
        void setWindowStyle(std::string style);
        void buildWindow(int width, int height);
        void startLoop(std::function<void()> customLoop);
};


#endif //ENGINE_H
