#include "./Point2D.h"

struct ColorRGB{
    int r;
    int g;
    int b;
};

class PrimitiveRenderer{
    private:
        static PrimitiveRenderer *pInstance; 

    private:
        PrimitiveRenderer();

    public:
        static PrimitiveRenderer &getInstance();
        void drawPoint(Point2D point, ColorRGB color);

};
