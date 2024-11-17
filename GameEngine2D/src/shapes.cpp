#include "./shapes.h"
#include <math.h>
#include "./PrimitiveRenderer.h"

void Circle::draw() const{
    PrimitiveRenderer::getInstance().drawCircle(center, radius, color);
}

void Circle::rotate(float angle){
    float radian = angle * M_PI / 180.0f;  
    float newX = center.x * cos(radian) - center.y * sin(radian);
    float newY = center.x * sin(radian) + center.y * cos(radian);

    center.x = newX;
    center.y = newY;
}

void Circle::translate(const Point2D& offset){
        center.x += offset.x;
        center.y += offset.y;
    }

void Circle::scale(float factor){
    radius *= factor;
}

void Triangle::draw() const {
    PrimitiveRenderer::getInstance().drawTriangle(point1, point2, point3, color);
}

void Triangle::translate(const Point2D& offset) {
    point1.x += offset.x;
    point1.y += offset.y;
    point2.x += offset.x;
    point2.y += offset.y;
    point3.x += offset.x;
    point3.y += offset.y;
}

void Triangle::rotate(float angle) {
    float radian = angle * M_PI / 180.0f;

    auto rotatePoint = [&](Point2D& p) {
        float newX = p.x * cos(radian) - p.y * sin(radian);
        float newY = p.x * sin(radian) + p.y * cos(radian);
        p.x = newX;
        p.y = newY;
    };

    rotatePoint(point1);
    rotatePoint(point2);
    rotatePoint(point3);
}

void Triangle::scale(float factor) {
    point1.x *= factor;
    point1.y *= factor;
    point2.x *= factor;
    point2.y *= factor;
    point3.x *= factor;
    point3.y *= factor;
}


void Rectangle::draw() const {
    PrimitiveRenderer::getInstance().drawRectangle(point1, point2, point3, point4, color);
}

void Rectangle::translate(const Point2D& offset) {
    point1.x += offset.x;
    point1.y += offset.y;
    point2.x += offset.x;
    point2.y += offset.y;
    point3.x += offset.x;
    point3.y += offset.y;
    point4.x += offset.x;
    point4.y += offset.y;
}

void Rectangle::rotate(float angle) {
    float radian = angle * M_PI / 180.0f;

    auto rotatePoint = [&](Point2D& p) {
        float newX = p.x * cos(radian) - p.y * sin(radian);
        float newY = p.x * sin(radian) + p.y * cos(radian);
        p.x = newX;
        p.y = newY;
    };

    rotatePoint(point1);
    rotatePoint(point2);
    rotatePoint(point3);
    rotatePoint(point4);
}

void Rectangle::scale(float factor) {
    point1.x *= factor;
    point1.y *= factor;
    point2.x *= factor;
    point2.y *= factor;
    point3.x *= factor;
    point3.y *= factor;
    point4.x *= factor;
    point4.y *= factor;
}

