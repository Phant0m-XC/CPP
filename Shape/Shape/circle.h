#pragma once
#include "shape.h"

class Circle : public Shape
{
	int rad;
	Shape::type tp = CIRCLE;
public:
	Circle() : Shape() {}
	~Circle() {}
	virtual void Set()
	{
		int x0, y0;
		cout << "¬ведите координаты:\nX=";
		cin >> x0;
		set_x(x0);
		cout << "Y=";
		cin >> y0;
		set_y(y0);
		cout << "¬ведите радиуса круга: ";
		cin >> rad;
	}
	virtual void Show()
	{
		cout << "-=ќ –”∆Ќќ—“№=-\n оординаты:\nX=" << get_x() << " Y=" << get_y() << " длинна радиуса: " << rad << endl;
	}
	virtual void Save()
	{
		int x0, y0;
		fstream file("base.bin", ios::out | ios::app | ios::binary);
		x0 = get_x();
		y0 = get_y();
		file.write((char*)&tp, sizeof(int));
		file.write((char*)&x0, sizeof(int));
		file.write((char*)&y0, sizeof(int));
		file.write((char*)&rad, sizeof(int));
		file.close();
	}
	virtual void Load(fstream &file)
	{
		int x0, y0;
		file.read((char*)&x0, sizeof(int));
		file.read((char*)&y0, sizeof(int));
		file.read((char*)&rad, sizeof(int));
		set_x(x0);
		set_y(y0);
	}
};