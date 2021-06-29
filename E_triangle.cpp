#include "stdafx.h"
#include "E_triangle.h"


IMPLEMENT_SERIAL(E_triangle, CObject, 1) //part of seralization

void E_triangle::Shape_Draw(CDC* dc) const {
	Triangle::Shape_Draw(dc);
}

void E_triangle::Redefine(CPoint start, CPoint end) {
	double a = abs(start.x - end.x);
	double height = (sqrt(3) / 2) * a;

	if (start.x < end.x && start.y < end.y) //right up
	{
		set_P2(start.x + a, start.y + height);
	}
	else if (start.x > end.x && start.y > end.y) //left up
	{
		set_P2(start.x - a, start.y - height);
	}
	else if (start.x < end.x && start.y > end.y) //right down
	{
		set_P2(start.x + a, start.y - height);
	}
	else if (start.x > end.x && start.y < end.y) //left down
	{
		set_P2(start.x - a, start.y + height);
	}

	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	CPoint p3;

	p3.x = abs(p2.x + p1.x) / 2;
	p3.y = p2.y;

	set_P3(p3.x, p3.y);
	set_P2(p2.x, p1.y);
}

bool E_triangle::isInside(const CPoint &P) const {
	bool flag = Triangle::isInside(P);
	return flag;
}

