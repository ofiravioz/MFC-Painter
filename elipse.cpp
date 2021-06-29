#include "stdafx.h"
#include "elipse.h"


IMPLEMENT_SERIAL(elipse, CObject, 1);//part of seralization

void elipse::Shape_Draw(CDC* dc) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

bool elipse::isInside(const CPoint &P) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	CPoint center;
	double a, b;
	bool flag = false;

	a = abs(p1.x - p2.x) / 2;
	b = abs(p1.y - p2.y) / 2;

	center.x = abs(p1.x + p2.x) / 2;
	center.y = abs(p1.y + p2.y) / 2;

	if ((((P.x - center.x)*(P.x - center.x)) / (a*a) + ((P.y - center.y)*(P.y - center.y)) / (b*b)) <= 1)
		flag = true;

	return flag;
}