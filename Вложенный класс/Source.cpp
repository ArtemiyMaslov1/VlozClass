//��������� ����� - ��� �����, ��������� ������������ ������ ������� ������.�, ���� ������ ����������
//������, ��� ������� ���������� ��������������, �� ������ ���������� ������ ������ ���� �������� � �������
//������, � ������� ���� ��������� ����� ������.�����, � ������� ������������ ������ ����� ��������
//����������.
//class A {/*�*/ };
//class B {
//public:
//	��������� ����� � �������������� ������ ������� ��������� ������ �
//	class A { � };
//	�����, ������������ ��������� ����� �
//	A* obj;
//};
//void main()
//��������� � �� ����� � ������ ������� ���������
//������� ����� ������������ ���������� ����� �
//A* obj2;
//}
//void main()
//��������� � �� ����� � ������ ������� ���������
//������� ����� ������������ ���������� ����� �
//A* obj2;
// ****************************************************
//class A {
//	A{
//	public:
//	class B {
//	friend class A; //���������� �����
//	B(int val = 0); //�����������
//	B* next;
//	//��������� �� ����������� �����
//	int value;
//private:
//	B*obj'
//};
//void main()
//{
//A::B*ptr;
//}
//class A {
//public:
//private:
//	class B {
//	public:
//		B(int val = 0);
//	};
//};
//
//A::B::B(int val)
//{
//	value = val;
//	next = 0;
//}
// ******************************
//int A::B::static_mem = 1024;
// ******************************
//class A
// 
//{
//public:
//	//....
//private:
//	//����� ���������� ���������� 
//	class B;
//	B* obj;
//};
//
//��� ���������� ������ �������� ������
//����������� ������
//class A::B {
// 
//public:
//	B(int val = 0);
//	B* next;
//	int value;
//};
//class A
//{
//public:
//	//.....
//private:
//	//���������� ����������
//	class B;
//	B* obj;
//	B x; //������: �������������� ��������� ���� B
//};
//
//*****************************
//class A {
//public:
//	//�
//private:
//	//���������� �:: �
//	class B;
//	class Ref {
//		//pi ����� ��� A::B*
//		B* pill;
//	};
//	//����������� �::�
//	class B {
//			//pref ����� ��� A::Ref
//			Ref* pref;
//	};
//};
//*******************
//class A
//{
//public:
//	int init(int);
//private:
//	class A::B
//	{
//	public:
//		B(int val = 0);
//		void mf(const A&);
//		int vaule;
//	};
//};
//A::B::B(int val)
////A::init() - ������������� ���� ������ A
////������ �������������� ����� ������ ���
////��������� �� ��� �
//value = init(val); //������: �������� ������������� INIT
//};
//void A::B::mf(A& il)
//{
//	//���������� � INIT () �� ������
//	memb = il.init();
//}

#include <iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point() { x = y = 0; }
	void SetPoint(int iX, int iY)
	{
		x = iX;
		y = iY;
	}

	void Show()
	{
		cout << "--------------------------------------";
		cout << x << "\t" << y << "\n\n";
	}
};
class Figure
{
	Point* obj;
	int count;
	int color;
public:
	Figure()
	{
		count = color = 0;
		obj = NULL;
	}
	void Createfigure(int cr, int ct)
	{
		if (ct < 3) exit(0);
		count = ct;
		color = cr;
		obj = new Point[count];
		if (!obj) exit(0);
		int tempX, tempY;
		for (int i = 0; i < count; i++)
		{
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}
	void ShowFigure()
	{
		cout << "----------------------------\n\n";
		cout << "Color" << color << "\n\nPoints- " << count << "\n\n";
			for (int i = 0; i < count; i++)
				obj[i].Show();
	}

	~Figure()
	{
		if (obj != NULL) delete[] obj;
	}
};

void main()
{
	Figure f;
	f.Createfigure(255, 3);
	f.ShowFigure();

}