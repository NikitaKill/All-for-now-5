#pragma once
#include "Geometry.h"

static class FigureAlligner
{
public:
	static void AllignToPoint(Rectangle* rectangle, double x, double y) {
		rectangle->SetPoint(Point(x, y));
	}
	static void AllignByRectangleCenter(Rectangle* rectangles, int rectangleCount, Rectangle* centerRectangle) {
		for (int i = 0; i < rectangleCount; i++)
		{
			FigureAlligner::AllignToPoint(&rectangles[i], centerRectangle->GetCenter()->getXcord(), centerRectangle->GetCenter()->getYcord());
		}
	}
};