#pragma once

#include "./Point2D.h"


class LineSegment {
	public:
		Point2D p1;
		Point2D p2;

	public:
		LineSegment(Point2D p1, Point2D p2);

		void draw(sf::RenderWindow& window) override;
    	 	void translate(float dx, float dy) override;
    	 	void rotate(float angle) override;
    	 	void scale(float factor) override;
};
