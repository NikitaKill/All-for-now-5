#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

static class DoubleValidator {
public:
	static bool IsValuePositive(double value) {
		return (value >= 0);
	}
	static bool IsValueInRange(double value, double min, double max) {
		return ((value >= min) && (value <= max));
	}
	static void AssertPositiveValue(double value) {
		if (!IsValuePositive(value))
		{
			throw exception("Negative value");
		}
	}
	static void AssertValueInRange(double value, double min, double max) {

		if (!IsValueInRange(value, min, max))
		{
			throw exception("wrong value range");
		}
	}
};

class Point
{
public:
	double getXcord() {
		return xCord;
	}
	double getYcord() {
		return yCord;
	}
	Point(double x = 123.0, double y = 123.0) {
		SetXcord(x);
		SetYcord(y);
	};

private:
	void SetXcord(double x) {
		DoubleValidator::AssertPositiveValue(x);
		xCord = x;
	}
	void SetYcord(double y) {
		DoubleValidator::AssertPositiveValue(y);
		yCord = y;
	}
	double xCord;
	double yCord;
};

class Ring
{
public:
	static int GetAllRingsCount() {
		return Ring::AllRingsCount;
	}

	void SetInternalRadius(double radIn) {
		DoubleValidator::AssertPositiveValue(radIn);
		internal_radius = radIn;
	}
	void SetExternalRadius(double radEx) {
		DoubleValidator::AssertPositiveValue(radEx);
		if (radEx < internal_radius)
		{
			throw exception("External radius cant be lesser than internal");
		}
		external_radius = radEx;
	}
	void SetCenterCords(Point centPoint) {
		center_point = centPoint;
	}

	double GetInternalRadius() {
		return internal_radius;
	}
	double GetExternalRadius() {
		return external_radius;
	}
	Point GetCenterCords() {
		return center_point;
	}


	double GetArea() {
		return (PI * ((external_radius * external_radius) - (internal_radius * internal_radius)));
	}
	Ring(double radIn = 0.0, double radEx = 0.0, Point centPoint = Point())
	{
		SetInternalRadius(radIn);
		SetExternalRadius(radEx);
		SetCenterCords(centPoint);
		AllRingsCount++;
	}
	~Ring() {
		AllRingsCount--;
	}
private:
	static int AllRingsCount;
	const double PI = 3.1415926;
	Point center_point;
	double internal_radius;
	double external_radius;
};
int Ring::AllRingsCount = 0;

class Rectangle
{
public:
	void SetLength(int x) {
		if (!x)
		{
			throw exception("Negative or null Length");
		}
		length = x;
	}
	void SetWidth(int y) {
		if (!y)
		{
			throw exception("Negative or null width");
		}
		width = y;
	}
	void SetPoint(Point Cent) {
		Center = Cent;
	}
	int GetWidth() {
		return width;
	}
	int GetLength() {
		return length;
	}
	Point* GetCenter() {
		return &Center;
	}
	Rectangle(Point Cent = Point(1, 1), int h = 1, int w = 1) {
		SetPoint(Cent);
		SetLength(h);
		SetWidth(w);
	};
	void WriteToConsole() {
		cout << "X = " << Center.getXcord() << " Y = " << Center.getXcord() << " Length = " << length << " Width = " << width << endl;
	}
private:
	Point Center;
	int length;
	int width;
};