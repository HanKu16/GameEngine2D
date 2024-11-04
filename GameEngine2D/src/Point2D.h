#pragma once

class Point2D{
    public:
        int x;
        int y;
    
    public:
        Point2D();
        Point2D(float xInput, float yInput);

        void draw(sf::RenderWindow& window) override;
        void translate(float dx, float dy) override;
        void rotate(float angle) override;
        void scale(float factor) override;
};
