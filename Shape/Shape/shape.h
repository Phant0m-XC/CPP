#pragma once
#include <fstream>
class Shape
{
	int x, y;
protected:
	enum type { SQUARE = 1, RECTANGLE, CIRCLE, ELLIPSE };
public:
	Shape() {}
	~Shape() {}
	virtual void Set() = 0;
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load(std::fstream&) = 0;
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	void set_x(int x0)
	{
		x = x0;
	}
	void set_y(int y0)
	{
		y = y0;
	}
};

