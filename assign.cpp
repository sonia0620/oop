/*----------------------------------*
	  源文件:assign.cpp
	  功能:Function Definitions
*-----------------------------------*/

/*-头文件-*/
#include "ASSIGN.h"
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;



/*-求解一元二次方程ax^2+bx+c=0的根-*/
void SolveEquation(float a, float b, float c)
{
	/*-先判断是否为一元二次方程-*/
	if (a == 0)
		cout << "equation of a degree , x = " << -c / b << endl;    //一元一次方程bx+c=0，x=-c/b
	else
	{
		float d = pow(b, 2) - 4 * a*c;    //△=b^2-4ac
		float m = -b / (2 * a);
		/*-再判断△正负-*/
		if (d == 0)
			cout << "equation of two degree , x1 = x2 = " << m << endl;    //△=0，单根x=-b/2a
		else if (d > 0)
		{
			float n = sqrt(d) / (2 * a);
			cout << "equation of two degree , x1=" << m + n << "x2=" << m - n << endl;    //△>0，x1、x2=（-b±√△）/2a
		}
		else
		{
			float n = sqrt(-d) / (2 * a);
			cout << "equation of two degree , x1=" << m << "+" << n << "i ; x2=" << m << "-" << n << "i" << endl;     //△<0，x1、x2=（-b±√-△ i）/2a
		}
	}    //一元二次方程ax^2+bx+c=0，根据求根法则求解

	cout << endl<<endl;
}


/*-实现对两个具有相同类型数据的交换-*/
int ValueSwap_1(char *x,char *y)
{
	int width_1 = strlen(x), width_2 = strlen(y);
    if (width_1==width_2)
    {
		char temp;
	    while (width_1--)
	    {
			temp = *x;
		    *x++ = *y;
		    *y++ = temp;
	    }
		return 1;
	}
	else return 0;
	
}//将两变量视作字符串数组实现值交换

/*
template<class T>
void ValueSwap_2(T &w, T &v)
{
	T tmp = w;
	w = v;
	v = tmp;
}
*///暂时不用




/*-根据三边长计算三角形的面积-*/
void CalcuTri(const float *p,const float *q,const float *n)
{
	if(*p+*q>*n&&*p+*n>*q&&*q+*n>*p)
	{
	float cos = (pow(*p, 2) + pow(*q, 2) - pow(*n, 2)) / (2 * *p * *q);
	float sin = sqrt(1 - pow(cos, 2));
	float area = *p * *q*sin / 2;
	cout << "the area is " << area << endl<<endl;
    }
	else cout << "these lengths can't form a triangle !" << endl<<endl;
}


/*-输入年月日判断这天是该年第几天、第几周-*/
void JudgeDay(int yr, int m, int d)
{
	int date =0,week= 0;
	int year[12] = { 31,28,31,30, 31,30,31,31, 30,31,30,31 };
	if (yr % 4 && (!yr % 100) || yr % 400)
		year[1] =29;	
	for (int i=0;i<m-1;i++)
			date += year[i];	
	date += d;
	cout << "the day is NO." << date << " day" << " ,in NO." << date/7+1 << " week of the year"<<endl;

}
