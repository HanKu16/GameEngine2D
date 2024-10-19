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

