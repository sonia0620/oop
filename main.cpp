/**************************************************
 **                功能 : exercise               **
/**************************************************/

/*----------------------------------*
			头文件：main.cpp
*-----------------------------------*/


/*-头文件-*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "EXERCISE.h"
using namespace std;



/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	/*-5.2-*/
	//B obj(10, 20, 30);

	/*-5.6-*/
	//Derived obj;

	/*-5.7-*/
	//Derived obj(200,300);
	//obj.show();
	////obj.d.show();

	/*-5.12-*/
	//Derived obj(10, 20);

	/*-5.13-*/
	Base b1(11);
	Derived d1(22, 33);

	b1 = d1;//第一种赋值
	cout << "b1.getb()=" << b1.getb() << endl;
	cout << "b1.getd()=" << b1.getd() << endl;

	Base* pb1 = &d1;//第二种赋值
	cout << "pb1->getb()=" << pb1->getb() << endl;
	cout << "pb1->getd()=" << pb1->getd() << endl;

	Derived* pd = &d1;
	Base* pb2 = pd;//第三种赋值
	cout << "pb2->getb()=" << pb2->getb() << endl;
	cout << "pb2->getd()=" << pb2->getd() << endl;

	Base& rb = d1;//第四种赋值
	cout << "rb.getb()=" << rb.getb() << endl;
	cout << "rb.getd()=" << rb.getd() << endl;

	//system("pause");
	
	return 0;

}