#pragma once
#include "figure.h"
class elipse :public figure
{
DECLARE_SERIAL(elipse)//part of seralization
public:
	elipse() {}//part of seralization
	elipse(const CPoint & p1, const CPoint & p2, const BOOL& b) :figure(p1, p2, b) {}
	void Shape_Draw(CDC* dc) const;
	bool isInside(const CPoint &P) const;
};

