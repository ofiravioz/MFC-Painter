#include "stdafx.h"
#include "Segment.h"

IMPLEMENT_SERIAL(Segment, CObject, 1)//part of seralization

void Segment::Shape_Draw(CDC* dc) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	dc->MoveTo(p1);//start point
	dc->LineTo(p2.x, p2.y);//to the end point
}

bool Segment::isInside(const CPoint &P) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	double totalD, d1, d2;
	bool flag = false;

	totalD = ((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	totalD = sqrt(totalD);
	d1 = ((p1.x - P.x)*(p1.x - P.x) + (p1.y - P.y)*(p1.y - P.y));
	d1 = sqrt(d1);
	d2 = ((p2.x - P.x)*(p2.x - P.x) + (p2.y - P.y)*(p2.y - P.y));
	d2 = sqrt(d2);

	if ((d1 + d2) <= (totalD + 2))
		flag = true;

	return flag;
}
