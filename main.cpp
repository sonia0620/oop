/*----------------------------------*
            头文件：main.cpp
*-----------------------------------*/


/*-头文件-*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "INHERIT.h"
using namespace std;



/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	/*-建立派生类对象,观察如何调用构造函数-*/
	derived1 d1(1, 2, 3);
	derived2 d2(4, 5, 6);
	derived3 d3(7, 8, 9);

	/*-统计基类对象创建个数-*/
	cout << "the number of objects of class base: " << base::statistic() << endl;
	
	/*-验证继承为全盘接受-*/
	cout << "the size of base: " << sizeof(base) << endl;
	cout << "the size of derived1: " << sizeof(derived1) << endl;
	cout << "the size of derived2: " << sizeof(derived2) << endl;
	cout << "the size of derived3: " << sizeof(derived3) << endl;


	/*-公有继承-*/
	d1.a = 9;//公有，可类外访问
	//d1.b = 8;//保护，不可类外访问
	//d1.c = 7;//继承但不可见
	d1.print();//公有（派生类对象可调用基类成员函数print()，间接访问基类数据）
	d1.show1();


	/*-保护继承-*/
	//d2.a = 6;//保护
	//d2.b = 5;//保护
	//d2.c = 4;//继承但不可见
	//d2.print();//保护
	d2.show2();
	

	/*-私有继承-*/
	//d3.a = 3;//私有
	//d3.b = 2;//私有
	//d3.c = 1;//继承但不可见
    //d3.print();//私有
    d3.show3();

	cout << "-------class Location-------" << endl;
	Location l1;
	l1.show();
	l1.move();
	l1.show();

	cout << "-------class Point-------" << endl;
	Point p1;
	p1.show();
	p1.move();
	p1.show();

	cout << "-------class Sphere-------" << endl;
	Sphere s1;
	s1.show();
	s1.move();
	s1.show();
	
	
	


	system("pause");
	
	return 0;
}