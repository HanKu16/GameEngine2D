#ifndef ENGINE_H
#define ENGINE_H

#include "./PrimitiveRenderer.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <functional>
#include <map>
#include <string>


enum Keyboard{
    Up = sf::Keyboard::Up,
    Down = sf::Keyboard::Down,
    Left = sf::Keyboard::Left,
    Right = sf::Keyboard::Right,
    Escape = sf::Keyboard::Escape,
    Space = sf::Keyboard::Space,
    Enter = sf::Keyboard::Enter,
};

enum Mouse{
    LeftClick = sf::Mouse::Button::Left,
    RightClick = sf::Mouse::Button::Right,
};

struct mouseCords{
    int x;
    int y;
};


//TODO delete try and catch and enum the keys
class Engine{ 
    private:
        sf::RenderWindow window;        

        int windowResolution[2];

        unsigned int windowStyle;

        int fps;

        sf::Clock clock;

        std::map<Keyboard, std::function<void()>> keyFunctionMap;

        std::map<Mouse, std::function<void()>> mouseFunctionMap;

        static Engine *pInstance;        

    private:
        Engine();

        void handleEvents();

    public:
        static Engine &getInstance(); 

        void setWindowSettings(int width, int height, std::string style);
        
        void setMaxFPS(int inFPS);

        float getElapsedTime();

        void restartClock();

        void clearToColor(ColorRGB color);

        void startLoop(std::function<void()> customLoop);

        void setFunctionKey(Keyboard key, std::function<void()> keyFunction);

        void setFunctionMouseButton(Mouse button, std::function<void()> mouseFunction);
        
        mouseCords getMousePosition();
};


#endif //ENGINE_H
