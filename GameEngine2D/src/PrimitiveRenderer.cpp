#include "PrimitiveRenderer.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


sf::Image PrimitiveRenderer::drawPoint(Point2D point, ColorRGB color, sf::Image &image){
	image.setPixel(point.x, point.y, sf::Color(color.r, color.g, color.b));
    return image;
}

sf::Image PrimitiveRenderer::drawLine(Point2D p1, Point2D p2, ColorRGB color, sf::Image& image) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    if (getAbsolute(dx) > getAbsolute(dy)) {
        if (p1.x > p2.x) {
            std::swap(p1, p2);
            dx = p2.x - p1.x;
            dy = p2.y - p1.y;
        }

        double m = dy / dx;
        double y = p1.y;

        for (int x = p1.x; x <= p2.x; x++) {
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
            y += m;
        }
    } else {
        if (p1.y > p2.y) {
            std::swap(p1, p2);
            dx = p2.x - p1.x;
            dy = p2.y - p1.y;
        }

        double m = dx / dy;
        double x = p1.x;
        for (int y = p1.y; y <= p2.y; y++) {
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
            x += m;
        }
    }

    return image;
}

double PrimitiveRenderer::getAbsolute(double value)
{
    return value > 0 ? value : value * (-1);
}


