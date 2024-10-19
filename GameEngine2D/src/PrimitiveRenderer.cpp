#include "PrimitiveRenderer.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


sf::Image PrimitiveRenderer::drawPoint(Point2D point, ColorRGB color, sf::Image &image){
	image.setPixel(point.x, point.y, sf::Color(color.r, color.g, color.b));
    return image;
}

// Implementation of drawLine using incremental algorithm
sf::Image PrimitiveRenderer::drawLine(Point2D p1, Point2D p2, ColorRGB color, sf::Image& image) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double m = dy / dx;

    if (m < 1 && m > -1) {
        for (int x = p1.x; x <= p2.x; x++) {
            int y = p1.y + m * (x - p1.x);
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
        }
    } else {
        m = dx / dy;
        for (int y = p1.y; y <= p2.y; y++) {
            int x = p1.x + m * (y - p1.y);
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
        }
    }

    return image;
}

double PrimitiveRenderer::getAbsolute(double value)
{
    return value > 0 ? value : value * (-1);
}


