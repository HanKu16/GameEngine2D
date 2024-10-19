#include "./PrimitiveRenderer.h"
#include "./Point2D.h"
#include "./LineSegment.h"

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

sf::Image PrimitiveRenderer::drawLineUsingDDA(LineSegment line, ColorRGB color, sf::Image& image) {
    drawLine(line.p1, line.p2, color, image);
    return image;
}

sf::Image PrimitiveRenderer::drawLineUsingDefault(const LineSegment& line, 
    ColorRGB color, sf::Image& image) {
    Point2D p1 = line.p1;
    Point2D p2 = line.p2;

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    if (getAbsolute(dx) > getAbsolute(dy)) {
        if (p1.x > p2.x) {
            std::swap(p1, p2);
            dx = p2.x - p1.x;
            dy = p2.y - p1.y;
        }

        double m = dy / dx;
        for (int x = p1.x; x <= p2.x; x++) {
            double y = (m * (x - p1.x)) + p1.y;
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
        }
    }
    else {
        if (p1.y > p2.y) {
            std::swap(p1, p2);
            dx = p2.x - p1.x;
            dy = p2.y - p1.y;
        }

        double m = dx / dy;
        for (int y = p1.y; y <= p2.y; y++) {
            double x = (m * (y - p1.y)) + p1.x;
            image.setPixel(x, y, sf::Color(color.r, color.g, color.b));
            x += m;
        }
    }

    return image;

}

sf::Image PrimitiveRenderer::drawRectangle(Point2D p1, Point2D p2, Point2D p3, Point2D p4, 
    ColorRGB color, sf::Image& image) {
    drawLine(p1, p2, color, image);
    drawLine(p2, p3, color, image);
    drawLine(p3, p4, color, image);
    drawLine(p4, p1, color, image);
    return image;
}

sf::Image PrimitiveRenderer::drawTriangle(Point2D p1, Point2D p2, Point2D p3, ColorRGB color, sf::Image& image) {
    drawLine(p1, p2, color, image);
    drawLine(p2, p3, color, image);
    drawLine(p3, p1, color, image);
    return image;
}

double PrimitiveRenderer::getAbsolute(double value)
{
    return value > 0 ? value : value * (-1);
}


