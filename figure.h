#pragma once
class figure :public CObject
{
	DECLARE_SERIAL(figure)//part of seralization

	CPoint P1;
	CPoint P2;
	BOOL Bold;
	COLORREF bgColor;
	COLORREF FbgColor;
public:
	figure() {}//part of seralization
	figure(const CPoint & p1, const CPoint& p2, const BOOL& b) : P1(p1), P2(p2), Bold(b) {}
	virtual void Serialize(CArchive& ar);//part of seralization
	void Draw(CDC *dc) const;//for drawing figures, insted of putting it at evry function we'll use inheritance
	virtual void Shape_Draw(CDC *dc) const;
	CPoint get_P1() const { return P1; }
	CPoint get_P2() const { return P2; }
	void set_P2(double x, double y) { P2.x = x; P2.y = y; }
	void set_P1(double x, double y) { P1.x = x; P1.y = y; }
	void setMBg(COLORREF c) { bgColor = c; }
	void setFBg(COLORREF c) { FbgColor = c; }
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(CPoint c1, CPoint c2);
};

