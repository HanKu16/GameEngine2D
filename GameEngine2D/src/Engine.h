#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
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

        int windowResolution[2];

        unsigned int windowStyle;

        int fps;

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

        void setWindowSettings(int width, int height, std::string style);
        
        void setMaxFPS(int inFPS);

        void clearToColor(int r, int g, int b);

        void startLoop(std::function<void()> customLoop);

        void setFunctionKey(std::string keyName, std::function<void()> keyFunction);

        void setFunctionMouseButton(std::string button, std::function<void()> mouseFunction);
        
        mouseCords getMousePosition();
};


#endif //ENGINE_H
