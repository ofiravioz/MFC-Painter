#include "stdafx.h"
#include "Circle.h"

IMPLEMENT_SERIAL(Circle, CObject, 1);//part of seralization

void Circle::Shape_Draw(CDC* dc) const {
	elipse::Shape_Draw(dc);
}

void Circle::Redefine(CPoint start, CPoint end)
{
	int max = fmax(abs(start.x - end.x), abs(start.y - end.y));

	if (start.x < end.x && start.y < end.y) //right up
	{
		set_P2(start.x + max, start.y + max);
	}
	else if (start.x > end.x && start.y > end.y) //left up
	{
		set_P2(start.x - max, start.y - max);
	}
	else if (start.x < end.x && start.y > end.y) //right down
	{
		set_P2(start.x + max, start.y - max);
	}
	else if (start.x > end.x && start.y < end.y) //left down
	{
		set_P2(start.x - max, start.y + max);
	}
}

bool Circle::isInside(const CPoint &P) const {
	bool flag = elipse::isInside(P);
	return flag;
}