#pragma once
class Ellipse : public Shape
{
	int length1;
	int length2;
	type tp = ELLIPSE;
public:
	Ellipse() : Shape() {}
	~Ellipse() {}
	virtual void Set()
	{
		int x0, y0;
		cout << "Введите координаты:\nX=";
		cin >> x0;
		set_x(x0);
		cout << "Y=";
		cin >> y0;
		set_y(y0);
		cout << "Введите длинну 1 стороны прямоугольника, описанного вокруг эллипса: ";
		cin >> length1;
		cout << "Введите длинну 2 стороны прямоугольника, описанного вокруг эллипса: ";
		cin >> length2;
	}
	virtual void Show()
	{
		cout << "-=Эллипс=-\nКоординаты:\nX=" << get_x() << " Y=" << get_y() << " длинна 1 стороны: " << length1 << " длинна 2 стороны: " << length2 << endl;
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
		file.write((char*)&length1, sizeof(int));
		file.write((char*)&length2, sizeof(int));
		file.close();
	}
	virtual void Load(fstream &file)
	{
		int x0, y0;
		file.read((char*)&x0, sizeof(int));
		file.read((char*)&y0, sizeof(int));
		file.read((char*)&length1, sizeof(int));
		file.read((char*)&length2, sizeof(int));
		set_x(x0);
		set_y(y0);
	}
};