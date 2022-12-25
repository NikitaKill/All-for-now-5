#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Geometry.h"

using namespace std;

static class CollisionManager {
public:
	static bool IsRectCollision(Rectangle& rec1, Rectangle& rec2) {
		bool NoXCollision = abs(rec1.GetCenter()->getXcord() - rec2.GetCenter()->getXcord()) < (abs(rec1.GetWidth() - rec2.GetWidth()) / 2);
		bool NoYCollision = abs(rec1.GetCenter()->getYcord() - rec2.GetCenter()->getYcord()) < (abs(rec1.GetLength() - rec2.GetLength()) / 2);
		return (NoXCollision && NoYCollision);
	}
	static bool IsRingCollision(Ring& ring1, Ring& ring2) {
		if ((ring1.GetCenterCords().getXcord() == ring2.GetCenterCords().getXcord()) && (ring1.GetCenterCords().getYcord() == ring2.GetCenterCords().getYcord()))
		{
			if (ring1.GetExternalRadius() > ring2.GetInternalRadius() || ring2.GetExternalRadius() > ring1.GetInternalRadius())
			{
				return false;
			}
		}
		else
		{
			double dX = ring1.GetCenterCords().getXcord() - ring2.GetCenterCords().getXcord();
			double dY = ring1.GetCenterCords().getYcord() - ring2.GetCenterCords().getYcord();
			double allRadius = ring1.GetExternalRadius() + ring2.GetExternalRadius();
			double sqrtrad = sqrt(pow(dX, 2) + pow(dY, 2));
			if (sqrtrad > allRadius)
			{
				return false;
			}
				
		}
		return true;
	}
};