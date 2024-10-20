#include "./PrimitiveRenderer.h"
#include "./Point2D.h"
#include "./LineSegment.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


PrimitiveRenderer::PrimitiveRenderer(sf::Image* image, int imageWidth, int imageHeight) {
    this->image = image;
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
}

void PrimitiveRenderer::drawPoint(Point2D point, ColorRGB color) {
	(*image).setPixel(point.x, point.y, sf::Color(color.r, color.g, color.b));
}

void PrimitiveRenderer::drawLine(Point2D p1, Point2D p2, ColorRGB color) {
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
            (*image).setPixel(x, y, sf::Color(color.r, color.g, color.b));
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
            (*image).setPixel(x, y, sf::Color(color.r, color.g, color.b));
            x += m;
        }
    }
}

void PrimitiveRenderer::drawLineUsingDDA(LineSegment line, ColorRGB color) {
    drawLine(line.p1, line.p2, color);
}

void PrimitiveRenderer::drawLineUsingDefault(const LineSegment& line, ColorRGB color) {
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
            (*image).setPixel(x, y, sf::Color(color.r, color.g, color.b));
        }
    } else {
        if (p1.y > p2.y) {
            std::swap(p1, p2);
            dx = p2.x - p1.x;
            dy = p2.y - p1.y;
        }

        double m = dx / dy;
        for (int y = p1.y; y <= p2.y; y++) {
            double x = (m * (y - p1.y)) + p1.x;
            (*image).setPixel(x, y, sf::Color(color.r, color.g, color.b));
            x += m;
        }
    }
}

void PrimitiveRenderer::drawOpenLine(std::vector<Point2D> points, ColorRGB color) {
    if (points.empty() || points.size() < 2) {
        return;
    }

    Point2D& lastPoint = *points.begin();

    for (int i = 1; i < points.size(); ++i) {
        Point2D& currentPoint = points[i];
        drawLine(lastPoint, currentPoint, color);
        lastPoint = currentPoint;
    }
}

void PrimitiveRenderer::drawClosedLine(std::vector<Point2D> points, ColorRGB color) {
    if (points.empty() || points.size() < 3) {
        return;
    }

    Point2D firstPoint = points[0];
    Point2D lastPoint = firstPoint;

    for (size_t i = 1; i < points.size(); ++i) {
        Point2D currentPoint = points[i];
        drawLine(lastPoint, currentPoint, color);
        lastPoint = currentPoint;
    }
    drawLine(lastPoint, firstPoint, color);
}

void PrimitiveRenderer::drawDashedLine(std::vector<LineSegment> lines, ColorRGB color) {
    for (const LineSegment& line : lines) {
        drawLineUsingDDA(line, color);
    }
}

void PrimitiveRenderer::drawRectangle(Point2D p1, Point2D p2, 
    Point2D p3, Point2D p4, ColorRGB color) {
    drawLine(p1, p2, color);
    drawLine(p2, p3, color);
    drawLine(p3, p4, color);
    drawLine(p4, p1, color);
}

void PrimitiveRenderer::drawTriangle(Point2D p1, Point2D p2, Point2D p3, ColorRGB color) {
    drawLine(p1, p2, color);
    drawLine(p2, p3, color);
    drawLine(p3, p1, color);
}

void PrimitiveRenderer::drawCircle(Point2D center, int radius, ColorRGB color) {
    if (radius <= 0) {
        return;
    }

    int x0 = center.x;
    int y0 = center.y;

    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;

    while (x >= y) {
        (*image).setPixel(x0 + x, y0 + y, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 + y, y0 + x, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 - y, y0 + x, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 - x, y0 + y, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 - x, y0 - y, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 - y, y0 - x, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 + y, y0 - x, sf::Color(color.r, color.g, color.b));
        (*image).setPixel(x0 + x, y0 - y, sf::Color(color.r, color.g, color.b));

        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

double PrimitiveRenderer::getAbsolute(double value) {
    return value > 0 ? value : value * (-1);
}


