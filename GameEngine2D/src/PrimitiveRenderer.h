#include "./Point2D.h"
#include "./LineSegment.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <vector>

struct ColorRGB{
    int r;
    int g;
    int b;
};

class PrimitiveRenderer{
    public:
        PrimitiveRenderer(sf::Image* image, int imageWidth, int imageHeight);
        sf::Image drawPoint(Point2D point, ColorRGB color, sf::Image &image);
        sf::Image drawLine(Point2D p1, Point2D p2, ColorRGB color, sf::Image& image);
        sf::Image drawLineUsingDDA(LineSegment line, ColorRGB color, sf::Image& image);
        sf::Image drawLineUsingDefault(const LineSegment& line, ColorRGB color, sf::Image& image);
        sf::Image drawOpenLine(std::vector<Point2D> points, ColorRGB color);
        sf::Image drawClosedLine(std::vector<Point2D> points, ColorRGB color);
        sf::Image drawDashedLine(std::vector<LineSegment> lines, ColorRGB color, sf::Image& image);
        sf::Image drawRectangle(Point2D p1, Point2D p2, Point2D p3, Point2D p4,
            ColorRGB color, sf::Image& image);
        sf::Image drawTriangle(Point2D p1, Point2D p2, Point2D p3, ColorRGB color, sf::Image& image);

    private:
        double getAbsolute(double value);

    private:
        sf::Image* image;
        int imageWidth;
        int imageHeight;
};
