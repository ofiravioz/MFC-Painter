#pragma once
#include "Triangle.h"
class E_triangle :
	public Triangle
{
	DECLARE_SERIAL(E_triangle)//part of seralization
public:
	E_triangle() {}//part of seralization
	E_triangle(const CPoint & p1, const CPoint& p2, const BOOL& b) :Triangle(p1, p2, b) {}
	void Shape_Draw(CDC* dc) const;
	virtual void Redefine(CPoint p1, CPoint p2);
	bool isInside(const CPoint &P) const;
};

