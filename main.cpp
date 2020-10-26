/*----------------------------------*
		 源文件 :main.cpp
		 功能 : 任务实现
 *-----------------------------------*/

/*-头文件-*/
#include"TASK.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
using namespace std;

/*----------------------------------*
         Class Definition
*-----------------------------------*/
	

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	
	//采用动态内存分配空间的方法, 计算斐波那契数列的前N项, 并将其存储在动态分配空间中
	cout << "-------TASK_1:Calculate the Fibonacci.-------"<<endl;
	
	int n; //项数
	cout << "enter in the number of terms:" << endl;
	cin >> n;
	Fib(n);
	
	

	//采用二分方法计算函数f(x)=0的根（默认单根）,采用指针实现, 精度误差控制在10^-6
	cout << "-------TASK_2:Solve the equation by dichotomy.-------" << endl;
	
	int m; //最高阶数
	cout << "enter in the highest order:" << endl;
	cin >> m;

	float *e = new float[m+1];//各阶系数
	cout << "enter in the factor of every order,from x^0 to the x^m:" << endl;
	for (int  i=0;i<m+1;i++)
		cin >>e[i];

	float l,h; //上下限
	cout << "enter in the upper and lower limits:" << endl;
	cin >> l>>h;

	float answer=Dic(m,e,l,h); //求解
	if (answer!=-1)
	{
		cout << "x=" << answer<< endl << endl;
	}
	else cout << "NO ANSWER!" << endl << endl; //输出

    
	
	//设计一款控制台窗口游戏（在规定步数内找到藏匿于‘#’阵的中的‘$’，游戏成功）
	cout << "-------TASK_3:Design a game.-------" << endl;
	const int ln = 5;//阵行数
	const int cn = 5;//阵列数
	const int stp = 3;//规定步数
	char map[ln][cn];
	Play(map,ln ,cn,stp ); //进行游戏
    


	//异常处理例题
	cout << "-------TASK_4:Exception handling.-------" << endl;
	char name[20];
	int age;
	float score;
	cout << "enter in the name :" << endl;
	cin >> name;
	cout << "enter in the age :" << endl;
	cin >> age;
	cout << "enter in the score :" << endl;
	cin >> score;
	try //检查是否出现异常
	{
		cout << "name :" << name << endl << "age :" << age << endl << "score :" << checkAgeScore(age, score) << endl;
	}
	catch (char) //捕获异常并做处理
	{
		cout << "except of format of age !" << endl;
	}
	catch (int)
	{
		cout << "except of format of score !" << endl;
	}

    
	

	system("pause");
	
	return 0;
}