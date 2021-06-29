#include "stdafx.h"
#include "figure.h"

IMPLEMENT_SERIAL(figure, CObject, 1)//part of seralization

void figure::Serialize(CArchive& ar)//part of seralization
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << bgColor;
		ar << FbgColor;
		ar << Bold;
	}
	else
	{
		ar >> P1;
		ar >> P2;
		ar >> bgColor;
		ar >> FbgColor;
		ar >> Bold;
	}
}

void figure::Shift(CPoint c1, CPoint c2)
{
	P2.x += (c1.x - c2.x);
	P2.y += (c1.y - c2.y);
	P1.x = c1.x;
	P1.y = c1.y;
}

void figure::Draw(CDC *dc) const {
	CPen pen(PS_SOLID, Bold ? 7 : 2, FbgColor);
	CPen *oldPen = dc->SelectObject(&pen);
	CBrush brush(bgColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	Shape_Draw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}

void figure::Shape_Draw(CDC* dc) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

bool figure::isInside(const CPoint &P) const {
	CPoint p1 = get_P1();
	CPoint p2 = get_P2();
	bool flag = false;

	if ((p1.x <= p2.x) && (p1.y <= p2.y)) {
		if (((P.x >= p1.x) && (P.x <= p2.x)) && ((P.y >= p1.y) && (P.y <= p2.y)))
			flag = true;
	}

	else if ((p1.x <= p2.x) && (p1.y >= p2.y)) {
		if (((P.x >= p1.x) && (P.x <= p2.x)) && ((P.y >= p2.y) && (P.y <= p1.y)))
			flag = true;
	}

	else if ((p1.x >= p2.x) && (p1.y <= p2.y)) {
		if (((P.x >= p2.x) && (P.x <= p1.x)) && ((P.y >= p1.y) && (P.y <= p2.y)))
			flag = true;
	}

	else if ((p1.x >= p2.x) && (p1.y >= p2.y)) {
		if (((P.x >= p2.x) && (P.x <= p1.x)) && ((P.y >= p2.y) && (P.y <= p1.y)))
			flag = true;
	}

	return flag;
}