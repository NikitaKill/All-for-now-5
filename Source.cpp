#include <iostream>
#include <stdio.h>
#include <random>
#include <string>
#include "Geometry.h"
#include "CollisionManager.h"
#include "FigureAligner.h"

using namespace std;

static class GeometricProgram {
public:
	static void DemoRing() {
		srand(time(0));
		 Ring rings[3];
		 for (int i = 0; i < 3; i++)
		 {
			 double in_rad = rand() % 20;
			 double ex_rad = rand() % 40 + 20;
			 rings[i].SetCenterCords(Point(1, 1));
			 rings[i].SetInternalRadius(in_rad);
			 rings[i].SetExternalRadius(ex_rad);
		 }
		 for (int i = 0; i < 3; i++)
		 {
			 cout << i << " (" << rings[i].GetCenterCords().getXcord() << "; " << rings[i].GetCenterCords().getXcord() << ") R = (" << rings[i].GetInternalRadius() << "; " << rings[i].GetExternalRadius() << ")" << endl;
			 cout << "Area " << i << " " << rings[i].GetArea() << endl;
		 }
		 cout << "Количество колец до вызова конструктора: " << Ring::GetAllRingsCount() << endl;
		 Ring* ring = new Ring(5.0, 10.0, Point(25.0, 25.0));
		 cout << "Количество колец после вызова конструктора: " << Ring::GetAllRingsCount() << endl;
		 delete ring;
		 cout << "Количество колец после вызова деструктора: " << Ring::GetAllRingsCount() << endl << endl;
	}
	static void DemoCollision() {
		Ring rings1[2] = { Ring(4, 5, Point(0, 0)), Ring(6, 7, Point(1, 1)) };
		cout << "Коллизия первой пары колец: " << CollisionManager::IsRingCollision(rings1[0], rings1[1]) << endl;
		Ring rings2[2] = { Ring(4, 5, Point(0, 0)) , Ring(6, 7, Point(20, 20)) };
		cout << "Коллизия второй пары колец: " << CollisionManager::IsRingCollision(rings2[0], rings2[1]) << endl;

		Rectangle rects1[2] = { Rectangle(Point(0, 0), 4, 5), Rectangle(Point(1, 1), 6, 7) };
		cout << "Коллизия первой пары прямоугольников: " << CollisionManager::IsRingCollision(rings1[0], rings1[1]) << endl;
		Rectangle rects2[2] = { Rectangle(Point(0, 0), 4, 5), Rectangle(Point(20, 20), 6, 7) };
		cout << "Коллизия второй пары прямоугольников: " << CollisionManager::IsRingCollision(rings2[0], rings2[1]) << endl;
	}
	static void DemoAligner() {
		Rectangle someRect = Rectangle(Point(123, 321), 123, 321);
		FigureAlligner::AllignToPoint(&someRect, 444, 555);
		cout << "Некоторый прямоугольник" << " (" << someRect.GetCenter()->getXcord() << "; " << someRect.GetCenter()->getYcord() << ") стороны = (" << someRect.GetLength() << "; " << someRect.GetWidth() << ")" << endl;
		Rectangle rects1[3] = { Rectangle(Point(0, 0), 1, 1), Rectangle(Point(1, 1), 2, 2), Rectangle(Point(2, 2), 3, 3)};
		for (int i = 0; i < 3; i++)
		{
			cout << i << " (" << rects1[i].GetCenter()->getXcord() << "; " << rects1[i].GetCenter()->getYcord() << ") стороны = (" << rects1[i].GetLength() << "; " << rects1[i].GetWidth() << ")" << endl;
		}
		cout << endl;
		FigureAlligner::AllignByRectangleCenter(rects1, 3, &someRect);
		for (int i = 0; i < 3; i++)
		{
			cout << i << " (" << rects1[i].GetCenter()->getXcord() << "; " << rects1[i].GetCenter()->getYcord() << ") стороны = (" << rects1[i].GetLength() << "; " << rects1[i].GetWidth() << ")" << endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	//GeometricProgram::DemoRing();
	//GeometricProgram::DemoCollision();
	GeometricProgram::DemoAligner();
	return 0;
}