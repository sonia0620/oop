/*----------------------------------*
            源文件：poly.cpp
			功能：Founcation Definitions
*-----------------------------------*/

#include "POLY.h"
#include <iostream>
using namespace std;

/*----------------------------------*
			整型数组类 Array
*-----------------------------------*/
Array::Array()
{
	size = DEFAULTSIZE;
	ps = new int[size];
	for (int i=0;i<size;i++)
		ps[i] = i + 1;
}
const int Array::DEFAULTSIZE = 5;//初始化默认数组大小

Array::Array(int a[], int n)
{
	size = n;
	ps = new int[size];
	for (int i = 0; i < size; i++)
		ps[i] = a[i];
}

Array::Array(const Array &aa)
{
	size = aa.size;
	ps = new int[size];
	for (int i = 0; i < size; i++)
		ps[i] = aa.ps[i];
}

void Array::Print()
{
	cout << "the elements:" << endl;

	for (int i = 0; i < size; i++)
		cout << ps[i] << "\t";

	cout << endl;
}

void Array::Alter()
{
	int i;
	cout << "alter which one?" << endl;
	cin >> i;
	cout << "alter to what?" << endl;
	cin >> ps[i - 1];
}

Array & Array::operator=(const Array &aa)
{
	if (ps)
		delete[]ps;

	size = aa.size;
	ps = new int[size];
	for (int i = 0; i < size; i++)
		ps[i] = aa.ps[i];

	return *this;
}

Array Array::operator+(const Array &aa)
{
	Array t = size > aa.size ? *this : aa;

	int temp = size > aa.size ? aa.size : size;
	for (int i = 0; i < temp; i++)
		t.ps[i] = ps[i] + aa.ps[i];

	return t;
}

Array operator-(const Array &aa,const Array &bb)
{
	Array t = aa.size > bb.size ? aa : bb;

	int temp = aa.size > bb.size ? bb.size : aa.size;
	for (int i = 0; i < temp; i++)
		t.ps[i] = aa.ps[i] - bb.ps[i];
	
	if (temp < bb.size)
		for (int i = temp; i < t.size; i++)
			t.ps[i] = -bb.ps[i];

	return t;
}

/*----------------------------------*
			抽象基类Shapes
*-----------------------------------*/

/*----------------------------------*
			派生矩形类Rectangle
*-----------------------------------*/
Rectangl::Rectangl()
{
	l = 3.0; w = 4.0;
}

Rectangl::Rectangl(float ll,float ww)
{
	l = ll; w = ww;
}

void Rectangl::display()
{
	cout << "A Rectangl: l=" << l << ", w=" << w << endl;
}

/*----------------------------------*
			点类Point
*-----------------------------------*/
Point::Point(float xx, float yy) : x(xx), y(yy)
{
}

void Point::show()
{
	cout << "(" << x << "," << y << ")";
}

/*----------------------------------*
			派生圆类Circle
*-----------------------------------*/
Circle::Circle():c(1.1,2.2)
{
	r = 5.0;
}

Circle::Circle(float xx, float yy, float rr):c(xx,yy),r(rr)
{
}

void Circle::display()
{
	cout << "A Circle: c=";
	c.show();
	cout << ", r=" << r << endl;
}

void DisplayShapes(Shapes *s) //顶层全局函数
{
	s->display();
}
