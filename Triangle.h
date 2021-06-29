#pragma once
#include "figure.h"
class Triangle :public figure
{
	DECLARE_SERIAL(Triangle)//part of seralization
private:
	CPoint P3;
	
public:
	Triangle() {}//part of seralization
	Triangle(const CPoint &p1, const CPoint& p2, const BOOL& b) : figure(p1, p2, b) {
		P3.x = p1.x;
		P3.y = p1.y;
	}
	void Serialize(CArchive& ar);//part of seralization
	CPoint get_P3() const { return P3; }
	void set_P3(double x, double y) { P3.x = x; P3.y = y; }

	void Shape_Draw(CDC* dc) const;
	virtual void Redefine(CPoint p1, CPoint p2);
	bool isInside(const CPoint &P) const;
	void Shift(CPoint c1, CPoint c2);

};

