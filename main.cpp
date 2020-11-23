/**************************************************
 ** 功能 :   研究生类 Graduate 的定义与实现      **
/**************************************************/

/*----------------------------------*
         头文件：main.cpp
*-----------------------------------*/

#include "GRADU.h"
#include <cstdlib>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;
const int N = 2;


/*----------------------------------*
         Main Function
*-----------------------------------*/

int main()
{
	Graduate g[N];//研究生对象数组
	for (int i = 0; i < N; i++)
		g[i].Print();

	string name1 = "Greeny";
	string tutor1 = "Chen Fengyuan";
	Graduate g1(name1, 1 , 20010574 , 97 , " Chinese language and literature ", tutor1);//普通研究生对象
	g1.Print();

	string name2 = "Sonia";
	string tutor2 = "Wu Ming";
	const Graduate g2(name2, 0, 20190129, 94, " Computer Science and Technology ", tutor2);//常研究生对象
	g2.Print();
	
	Graduate::GetAver();//所有研究生的平均成绩

	for (int i = 0; i < N; i++)
		GetGrade(g[i]);
	GetGrade(g1);
	GetGrade(g2);//成绩等级

	
	system("pause");
	
	return 0;
}