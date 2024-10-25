#include <SFML/Graphics.hpp>
#include "./PrimitiveRenderer.h"
#include "./Point2D.h"
#include "./LineSegment.h"

int main() {
    // Create a render window
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Pixel Example");

    // Create an image (100x100 pixels)
    sf::Image image;
    int imageWidth = 800;
    int imageHeight = 800;
    image.create(800, 800, sf::Color::Black);

    PrimitiveRenderer primitiveRenderer = PrimitiveRenderer(&image, imageWidth, imageHeight);

    ColorRGB red = { 255, 0, 0 };
    ColorRGB green = { 0, 255, 0 };
    ColorRGB blue = { 0, 0, 255 };
    ColorRGB black = { 0, 0, 0 };

    //Test drawing point
    //primitiveRenderer.drawPoint(Point2D(400, 400), green);
    //primitiveRenderer.drawPoint(Point2D(401, 400), green);
    //primitiveRenderer.drawPoint(Point2D(402, 400), green);
    //primitiveRenderer.drawPoint(Point2D(403, 400), green);
    //primitiveRenderer.drawPoint(Point2D(404, 400), green);
    //primitiveRenderer.drawPoint(Point2D(405, 400), green);



    //Test drawing lines
    LineSegment line = LineSegment(Point2D(100, 700), Point2D(200, 100));
    //using points
    //primitiveRenderer.drawLine(Point2D(100, 700), Point2D(200, 100), blue);
    //primitiveRenderer.drawLine(Point2D(735, 50), Point2D(235, 50), red);
    //primitiveRenderer.drawLine(Point2D(30, 500), Point2D(700, 500), green);

    //using DDA
    //primitiveRenderer.drawLineUsingDDA(line, green);

    //using default
    //primitiveRenderer.drawLineUsingDefault(line, blue);



    //Test drawing open/close line
    //Point2D a = Point2D(100, 635);
    //Point2D b = Point2D(360, 255);
    //Point2D c = Point2D(740, 525);
    //Point2D d = Point2D(120, 125);
    //Point2D e = Point2D(450, 675);
    //Point2D f = Point2D(420, 275);
    //std::vector<Point2D> points = { a, e, c, d };

    //open
    //primitiveRenderer.drawOpenLine(points, red);

    //closed
    //primitiveRenderer.drawClosedLine(points, red);



    //Test drawing dashed line
    //std::vector<LineSegment> dashedLine = {
    //    LineSegment(Point2D(0, 0), Point2D(50, 50)),
    //    LineSegment(Point2D(100, 100), Point2D(150, 150)),
    //    LineSegment(Point2D(200, 200), Point2D(250, 250)),
    //    LineSegment(Point2D(300, 300), Point2D(350, 350)),
    //    LineSegment(Point2D(400, 400), Point2D(450, 450)),
    //};
    //primitiveRenderer.drawDashedLine(dashedLine, blue);



    //Test drawing recktangle
    primitiveRenderer.drawRectangle(Point2D(500, 600), Point2D(400, 600), Point2D(400, 500), Point2D(500, 500), green);
    primitiveRenderer.boundaryFill(Point2D(450, 550), green, green);

    primitiveRenderer.drawCircle(Point2D(200, 200), 50, green);
    primitiveRenderer.boundaryFill(Point2D(200, 200), green, green);


    //Test drawing triangle
    primitiveRenderer.drawTriangle(Point2D(100, 635), Point2D(360, 255), Point2D(740, 525), blue);
    primitiveRenderer.boundaryFill(Point2D(360, 300), blue, blue);





    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
