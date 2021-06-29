#pragma once
#include "figure.h"
class rectangle: public figure
{
	DECLARE_SERIAL(rectangle)//סרלזציה
public:
	rectangle() {}//סרלזציה
	rectangle(const CPoint & p1, const CPoint & p2, const BOOL & b) :figure(p1, p2, b) {}
	virtual void Shape_Draw(CDC* dc) const;
	bool isInside(const CPoint &P) const;
};

