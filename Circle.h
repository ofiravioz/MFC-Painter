#pragma once
#include "elipse.h"
class Circle : public elipse
{
	DECLARE_SERIAL(Circle)//part of seralization
public:
	Circle() {}//part of seralization
	Circle(const CPoint & p1, const CPoint & p2, const BOOL & b) :elipse(p1, p2, b) {}
	void Shape_Draw(CDC* dc) const;
	void Redefine(CPoint start, CPoint end);
	bool isInside(const CPoint &P) const;
};

