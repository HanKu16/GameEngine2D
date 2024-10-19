#include "PrimitiveRenderer.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


sf::Image PrimitiveRenderer::drawPoint(Point2D point, ColorRGB color, sf::Image &image)
{
	image.setPixel(point.x, point.y, sf::Color(color.r, color.g, color.b));
    return image;
}
