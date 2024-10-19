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
};
