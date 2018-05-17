#pragma once
class Square : public Shape
{
	int length;
	type tp = SQUARE;
public:
	Square() : Shape() {}
	~Square() {}
	virtual void Set()
	{
		int x0, y0;
		cout << "������� ����������:\nX=";
		cin >> x0;
		set_x(x0);
		cout << "Y=";
		cin >> y0;
		set_y(y0);
		cout << "������� ������ ��������: ";
		cin >> length;
	}
	virtual void Show()
	{
		cout << "-=�������=-\n����������:\nX=" << get_x() << " Y=" << get_y() << " ������ �������: " << length << endl;
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
		file.write((char*)&length, sizeof(int));
		file.close();
	}
	virtual void Load(fstream &file)
	{
		int x0, y0;
		file.read((char*)&x0, sizeof(int));
		file.read((char*)&y0, sizeof(int));
		file.read((char*)&length, sizeof(int));
		set_x(x0);
		set_y(y0);
	}
};