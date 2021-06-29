#include "stdafx.h"
#include "S_triangle.h"

IMPLEMENT_SERIAL(S_triangle, CObject, 1)//part of seralization

void S_triangle::Shape_Draw(CDC* dc) const {
	Triangle::Shape_Draw(dc);
}

void S_triangle::Redefine(CPoint start, CPoint end) {
	figure::Redefine(start, end);

	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	CPoint p3;

	p3.x = p1.x;
	p3.y = p2.y;

	set_P3(p3.x, p3.y);
	set_P2(p2.x, p1.y);
}

bool S_triangle::isInside(const CPoint &P) const {
	bool flag = Triangle::isInside(P);
	return flag;
}
