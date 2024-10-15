#include "PrimitiveRenderer.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

void PrimitiveRenderer::drawPoint(Point2D point, Color color){
    sf::Image::setPixel(point.x, point.y, sf::Color(color.r, color.g, color.b));
}
