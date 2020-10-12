/*----------------------------------*
        源文件:main.cpp
	    功能:任务实现
*-----------------------------------*/

/*-头文件-*/
#include <cstdlib>  //相当于C中<stdlib.h>
#include <windows.h>
#include "ASSIGN.h"
#include <iostream>
using namespace std;

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	/*-求解一元二次方程ax^2+bx+c=0的根-*/
	cout << "---------- assign_1.solve equation ax^2+bx+c=0 ----------:"<<endl;
	float a, b, c;
	cout << "enter in a,b,c :" << endl;
	cin >> a >> b >> c;
	SolveEquation(a, b, c);


	/*-实现对两个具有相同类型数据的交换-*/
	cout << "---------- assign_2.exchange the values of two variables of the same class ----------:"<<endl;
	char x[30], y[30];
	cout << "enter in x,y :" << endl;
	cin >> x >> y;
	if(ValueSwap_1(x, y))
		cout << "after swapping , x is " <<x << " , y is " << y <<endl<<endl<<endl;
	else cout << "these two variables have different class !" << endl << endl << endl;

	
	/*
	int w, v;
	cout << "enter in integer w,v :" << endl;
	cin >> w >> v;
	ValueSwap_2(w, v);
	cout << "after swapping , w is " << w << " , v is " << v << endl << endl << endl;
	*///暂时不用
	


	/*-根据三边长计算三角形的面积-*/
	cout << "---------- assign_3.calculate the area of triangle ----------:"<<endl;
	float p, q, n;
	cout << "enter in lengths of each side :" << endl;
	cin >> p >> q >> n;
	CalcuTri(&p, &q, &n); 


	/*-输入年月日判断这天是该年第几天、第几周-*/
	cout << "---------- assign_4.judge a day is what day and in what week of the year ----------:" << endl;
	int yr,m,d;
	char hyphen;
	cout << "enter in the data following format of 2020-10-06 :" << endl;
	cin >> yr >>hyphen>> m >>hyphen>> d;
	JudgeDay(yr, m, d);





	system("pause");
	
	return 0;
}

