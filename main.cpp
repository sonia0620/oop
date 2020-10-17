/*----------------------------------*          
         源文件 :main.cpp 
         功能 : 任务实现
 *-----------------------------------*/

/*-头文件-*/
#include"STICK.h"
#include<windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXSIZE = 40;//最大木棍数量

/*----------------------------------*
            Main Function 
*-----------------------------------*/


int main()
{

	float lens[MAXSIZE];//木棍长度数组
	int m;//实际木棍数量

	cout << "enter in the number of sticks ( >=3 ):" << endl;
	cin >> m;
	cout << "enter in the lengths of them :" << endl;
	for (int i = 0; i < m; i++)
		cin >> lens[i];

	Max_C(lens, m);
	Max_S(lens, m);

	system("pause");
	return 0;

}