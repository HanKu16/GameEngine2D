#pragma once

class Point2D{
    public:
        int x;
        int y;
    
    public:
        Point2D();
        Point2D(float xInput, float yInput);
        void rotate(float angle);
        void translate(float dx, float dy);
};
