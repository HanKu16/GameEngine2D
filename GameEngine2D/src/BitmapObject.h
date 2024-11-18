#pragma once

#include <SFML/Graphics.hpp>

class BitmapObject{
    private:
        sf::Texture texture; 
        sf::Sprite sprite;

    public:
        void loadBitmap(std::string &filepath);

};
