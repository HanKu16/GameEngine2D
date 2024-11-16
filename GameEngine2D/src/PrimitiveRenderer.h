#include "./Point2D.h"
#include "./LineSegment.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <vector>

struct ColorRGB {
    int r;
    int g;
    int b;
};

class PrimitiveRenderer {
    public:
        PrimitiveRenderer(sf::Image* image, int imageWidth, int imageHeight);
        void drawPoint(Point2D point, ColorRGB color);
        void drawLine(Point2D p1, Point2D p2, ColorRGB color);
        void drawLineUsingDDA(LineSegment line, ColorRGB color);
        void drawLineUsingDefault(const LineSegment& line, ColorRGB color);
        void drawOpenLine(std::vector<Point2D> points, ColorRGB color);
        void drawClosedLine(std::vector<Point2D> points, ColorRGB color);
        void drawDashedLine(std::vector<LineSegment> lines, ColorRGB color);
        void drawRectangle(Point2D p1, Point2D p2, Point2D p3, Point2D p4, ColorRGB color);
        void drawTriangle(Point2D p1, Point2D p2, Point2D p3, ColorRGB color);
        void drawCircle(Point2D center, int radius, ColorRGB color);
        void drawEllipse(Point2D center, int r1, int r2, ColorRGB color);
        void boundaryFill(Point2D p, ColorRGB fillColor, ColorRGB boundaryColor);
        void floodFill(Point2D p, ColorRGB fillColor, ColorRGB backgroundColor);

    private:
        double getAbsolute(double value);

    private:
        sf::Image* image;
        int imageWidth;
        int imageHeight;
};
