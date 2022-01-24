//Вложенный класс - это класс, полностью определенный внутри другого класса.и, если объект обыночного
//класса, как правило существуют самостоятельно, то объект вложенного класса должен быть привязан к объекту
//класса, в котором этот вложенный класс описан.Класс, в который вкладывается другой класс называют
//объемлющим.
//class A {/*…*/ };
//class B {
//public:
//	вложенный класс А инкапсулирован внутри области видимости класса В
//	class A { … };
//	Здесь, используется вложенный класс А
//	A* obj;
//};
//void main()
//вложенный А не видим в данной области видимости
//поэтому здесь используется глобальный класс А
//A* obj2;
//}
//void main()
//вложенный А не видим в данной области видимости
//поэтому здесь используется глобальный класс А
//A* obj2;
// ****************************************************
//class A {
//	A{
//	public:
//	class B {
//	friend class A; //Объявление друга
//	B(int val = 0); //конструктор
//	B* next;
//	//указатель на собственный класс
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
//	//здесь объявление необхадимо 
//	class B;
//	B* obj;
//};
//
//имя вложенного класса отмечено именем
//объемлющего класса
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
//	//объявление необхадимо
//	class B;
//	B* obj;
//	B x; //ошибка: неопределенный вложенный клас B
//};
//
//*****************************
//class A {
//public:
//	//…
//private:
//	//объявление А:: В
//	class B;
//	class Ref {
//		//pi имеет тип A::B*
//		B* pill;
//	};
//	//определение А::В
//	class B {
//			//pref имеет тип A::Ref
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
////A::init() - нестатический член класса A
////должен использоваться через объект или
////указатель на тип А
//value = init(val); //ошибка: неверное использование INIT
//};
//void A::B::mf(A& il)
//{
//	//обращаемся к INIT () по ссылке
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