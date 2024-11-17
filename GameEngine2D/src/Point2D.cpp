#include "./Point2D.h"

#include <cmath>

Point2D::Point2D() {
    x = 0;
    y = 0;
}

Point2D::Point2D(float xInput, float yInput){
    x = round(xInput);
    y = round(yInput);
}

void Point2D::rotate(float angle) {
    float angleRadians = angle * (M_PI / 180.0f);
    float newX = x * cos(angleRadians) - y * sin(angleRadians);
    float newY = x * sin(angleRadians) + y * cos(angleRadians);
    x = newX;
    y = newY;
}

void Point2D::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

