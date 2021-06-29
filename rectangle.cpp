#include "stdafx.h"
#include "rectangle.h"


IMPLEMENT_SERIAL(rectangle, CObject,1)//part of seralization

void rectangle::Shape_Draw(CDC* dc) const {
	figure::Shape_Draw(dc);
}

bool rectangle::isInside(const CPoint &P) const {
	bool flag = figure::isInside(P);
	return flag;
}
