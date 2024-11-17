#ifndef ENGINE_H
#define ENGINE_H

#include "../src/Point2D.h"
#include "../src/LineSegment.h"
#include "../src/Types.h"


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <functional>
#include <map>
#include <string>



class Engine{ 
    private:
        sf::RenderWindow window;        

        WindowResolution windowResolution;

        sf::Image image;

        int fps;

        sf::Clock clock;

        std::map<Keyboard, std::function<void()>> keyFunctionMap;

        std::map<Mouse, std::function<void()>> mouseFunctionMap;

        static Engine *pInstance;        

    private:
        Engine();

        void handleEvents();

        void drawWindow();

    public:
        static Engine &getInstance(); 

        void setWindowSettings(int width, int height, WindowStyle style);

        ImageConf getImageConf();
        
        void setMaxFPS(int inFPS);

        float getElapsedTime();

        void restartClock();

        void clearToColor(ColorRGB color);

        void startLoop(std::function<void()> customLoop);

        void setFunctionKey(Keyboard key, std::function<void()> keyFunction);

        void setFunctionMouseButton(Mouse button, std::function<void()> mouseFunction);
        
        MouseCords getMousePosition();
};


#endif //ENGINE_H
