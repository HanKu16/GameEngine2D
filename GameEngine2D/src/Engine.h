#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <functional>
#include <map>
#include <string>



struct mouseCords{
    int x;
    int y;
};

class Engine{ 
    private:
        sf::RenderWindow window;        

        unsigned int windowStyle;

        std::map<std::string, sf::Keyboard::Key> keyMap; 

        std::map<std::string, std::function<void()>> keyFunctionMap;

        std::map<std::string, sf::Mouse::Button> mouseButtonsMap;
        
        std::map<std::string, std::function<void()>> mouseFunctionMap;

        static Engine *pInstance;        

    private:
        Engine();

        void initMapping();

        void handleEvents();
        
    public:
        static Engine &getInstance(); 

        void setWindowStyle(std::string style);

        void buildWindow(int width, int height);

        void startLoop(std::function<void()> customLoop);

        void setFunctionKey(std::string keyName, std::function<void()> keyFunction);

        void setFunctionMouseButton(std::string button, std::function<void()> mouseFunction);
        
        mouseCords getMousePosition();
};


#endif //ENGINE_H
