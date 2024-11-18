#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

struct ColorRGB {
    int r;
    int g;
    int b;
};

enum WindowStyle{
    Window = sf::Style::Default,
    Fullscreen = sf::Style::Fullscreen
};

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

struct MouseCords{
    int x;
    int y;
};

struct WindowResolution{
    int width;
    int height;
};

struct CanvasConf{
    sf::Image *image;
    int width;
    int height;
};
