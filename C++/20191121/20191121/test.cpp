#include<iostream>
#pragma warning(disable:4996)
using namespace std;

class CGoods
{
public:
	void RegisterGoods(char* name, int count, float price)
	{
		strcpy(this->name, name);
		this->count = count;
		this->price = price;
	}
	void SetName(char* name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return name;
	}
	int GetCount()
	{
		return count;
	}
	float GetPrice()
	{
		return price;
	}
	float GetTotalPrice()
	{
		return price * count;
	}
private:
	char name[10];
	int count;
	float price;
	float total_price;
};

void main()
{
	CGoods c1;
	c1.RegisterGoods("C++", 10, 35);
	cout << c1.GetName() << endl;
}





//class Student
//{
//public:
//	void ResgisterStu(char* n, char* s, int a, int h, int w)
//	{
//		strcpy(name, n);
//		strcpy(sex, s);
//		age = a;
//		height = h;
//		weight = w;
//	}
//private:
//	char name[10];
//	char sex[3];
//	int age;
//	int height;
//	int weight;
//};
//
//void main()
//{
//	Student s;
//	s.ResgisterStu("张三","男", 20, 170, 50);
//}






//void main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8 };
//	for (auto ele : ar)
//		cout << ele << " ";
//	cout << endl;
//}
//




//namespace myspace
//{
//	void fun()
//	{
//		cout << "fun1" << endl;
//	}
//}
//
//namespace youspace
//{
//	void fun()
//	{
//		cout << "fun" << endl;
//	}
//}
//
//void main()
//{
//	//cout << "Hello World!" << endl;
//	//int a = 10;
//	//char c = 'ABC';
//	//float b = 3.1415926;
//	//cout << a << endl;
//	//cout << b << endl;
//	//cout << c << endl;
//	//作用域访问符
//	youspace::fun();
//}