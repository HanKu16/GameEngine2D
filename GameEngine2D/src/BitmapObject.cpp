#include "BitmapObject.h"
#include <string>
#include "Engine.h"

void BitmapObject::loadBitmap(std::string &filepath){
    texture.loadFromFile(filepath); 
    sf::Sprite sprite;
    sprite.setTexture(texture);
    Engine::getInstance().addToDrawablesQueue(sprite);;
}
