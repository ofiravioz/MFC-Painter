#pragma once
#include "figure.h"
class Segment:public figure
{
	DECLARE_SERIAL(Segment)//part of seralization
public:
	Segment() {}//part of seralization
	Segment(const CPoint & p1, const CPoint& p2, const BOOL& b) :figure(p1, p2, b) {}
	void Shape_Draw(CDC* dc) const;
	bool isInside(const CPoint &P) const;
};

