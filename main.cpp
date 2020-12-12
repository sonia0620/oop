/**************************************************
 **             功能 : 类的多态性                **
/**************************************************/


/*----------------------------------*
            源文件：main.cpp
*-----------------------------------*/



/*-头文件-*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "POLY.h"
using namespace std;


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	int e1[6] = { 2,3,5,7,11,13 };
	Array a1(e1,6);
	cout << "a1 "; a1.Print();

	
	a1.Alter();
	cout << "after alter, a1 "; a1.Print(); cout << endl;


	int e2[7] = { 2,4,6,8,10,12,14 };
	Array a2(e2, 7);
	cout << "a2 "; a2.Print();

	
	a2 = a1;
	cout << "after assign a1 to a2, a2 "; a2.Print(); cout << endl;


	Array a3= a1 + a2;
	cout << "a3= a1 + a2, a3 "; a3.Print(); cout << endl;

	Array a4 = a1 - a2;
	cout << "a4= a1 - a2, a4 "; a4.Print(); cout << endl;
	Array a5 = a2 - a1;
	cout << "a5= a2 - a1, a4 "; a5.Print(); cout << endl;



	Shapes *p[2];// 抽象类Shapes类型的指针数组

	// 指针指向派生类对象
	p[0] = new Rectangl(3.45, 5.67);
	p[1] = new Circle(6.6, 7.7, 9.0);

	//1.通过指针访问派生类各自的display()函数
	p[0]->display();
	p[1]->display();
	
	//2.调用顶层全局函数
	DisplayShapes(p[0]);
	DisplayShapes(p[1]);

	






	system("pause");
	
	return 0;
}