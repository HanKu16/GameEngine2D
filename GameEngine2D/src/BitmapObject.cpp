#include "BitmapObject.h"
#include <string>
#include "Engine.h"

void BitmapObject::loadBitmap(std::string &filepath, float x, float y){
    texture.loadFromFile(filepath); 
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    Engine::getInstance().addToDrawablesQueue(sprite);
}
