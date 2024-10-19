#include "./Point2D.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

struct ColorRGB{
    int r;
    int g;
    int b;
};

class PrimitiveRenderer{
    public:
        sf::Image drawPoint(Point2D point, ColorRGB color, sf::Image &image);
        sf::Image drawLine(Point2D p1, Point2D p2, ColorRGB color, sf::Image& image);
        sf::Image drawRectangle(Point2D p1, Point2D p2, Point2D p3, Point2D p4,
            ColorRGB color, sf::Image& image);

    private:
        double getAbsolute(double value);
};
