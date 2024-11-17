#pragma once
#include "./ShapeObject.h"
#include "./Types.h"

class Circle : public ShapeObject {
    private:
        Point2D center;
        float radius;
        ColorRGB color;

    public:
        Circle(Point2D center, float radius, ColorRGB color) : center(center), radius(radius), color(color){}

        void draw() const override;

        void translate(const Point2D& offset) override; 

        void rotate(float angle) override;

        void scale(float factor) override;
            
};

class Triangle : public ShapeObject {
private:
    Point2D point1;
    Point2D point2;
    Point2D point3;
    ColorRGB color;

public:
    Triangle(Point2D point1, Point2D point2, Point2D point3, ColorRGB color)
        : point1(point1), point2(point2), point3(point3), color(color) {}

    void draw() const override;

    void translate(const Point2D& offset) override;

    void rotate(float angle) override;

    void scale(float factor) override;
};

class Rectangle : public ShapeObject {
private:
    Point2D point1;
    Point2D point2;
    Point2D point3; 
    Point2D point4;
    ColorRGB color;

public:
    Rectangle(Point2D point1, Point2D point2, Point2D point3, Point2D point4, ColorRGB color)
        : point1(point1), point2(point2), point3(point3), point4(point4), color(color) {}

    void draw() const override;

    void translate(const Point2D& offset) override;

    void rotate(float angle) override;

    void scale(float factor) override;
};
