#include "stdafx.h"
#include "Square.h"

IMPLEMENT_SERIAL(Square, CObject, 1)//part of seralization

void Square::Shape_Draw(CDC* dc) const {
	rectangle::Shape_Draw(dc);
}

void Square::Redefine(CPoint start, CPoint end)
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

bool Square::isInside(const CPoint &P) const {
	bool flag = rectangle::isInside(P);
	return flag;
}