#pragma once
#include "rectangle.h"
class Square :
	public rectangle
{
	DECLARE_SERIAL(Square)//part of seralization
public:
	Square() {}//part of seralization
	Square(const CPoint &p1, const CPoint& p2, const BOOL& b) : rectangle(p1, p2, b) {}
	void Shape_Draw(CDC* dc) const;
	void Redefine(CPoint start, CPoint end);
	bool isInside(const CPoint &P) const;
};

