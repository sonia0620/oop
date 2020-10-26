/*----------------------------------*
	 源文件 :task.cpp
	 功能 :Function Definitions
*-----------------------------------*/

/*-头文件-*/
#include"TASK.h"
#include<cmath>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include<iostream>
using namespace std;


//采用动态内存分配空间的方法, 计算斐波那契数列的前N项（F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 3，n ∈ N*））, 并将其存储在动态分配空间中
int Fib(int n)
{
	if (n<=0||int(n)!=n)
	{
		cout << "ERROR!" << endl;
		return 0;
	} //判断项数是否为正整数
	int *f = new int[n]; //动态分配内存空间
	int i;
	for ( i= 0; i <n; i++)
	{
		if (i==0||i==1)
			f[i] = i;
		else
		f[i] = f[i - 1] + f[i - 2];
	} //计算斐波那契数列的前n项
	for ( i = 0; i < n; i++)
	{
		cout << "f[" << i << "]= " << f[i] << endl;
	} //输出斐波那契数列的前n项
	delete(f);
	return 1;

}


//采用二分方法计算函数f(x)=0的根（默认单根）,采用指针实现, 精度误差控制在10^-6

/*-求自变量x对应函数值-*/
float Value(int m, float *e, float x)
{
	float v = 0;
	for (int i=0;i<m+1;i++)
	{
		v += e[i] * pow(x, i);
	}
	return v;

}
//二分法求解方程根
float Dic(int m, float *e,float l,float h)
{	
	float mid= (l + h) / 2.0; //取区间中点
	while (Value(m,e,l)*Value(m,e,h)<0&&fabs(l-h)>1e-6) //当上下限函数值异号且当前根未达到精度要求
	{
	    mid = (l + h) / 2.0;
		if (Value(m,e,l)*Value(m,e,mid) < 0) //中点和下限函数值异号
			h = mid;  //修改上限
		else  //中点和上限函数值异号
			l = mid;  //修改下限
	}
	if (Value(m,e,l) == 0) //初始或求解过程中，下限函数值为0
		return l;
	else if (Value(m,e,h) == 0) //初始或求解过程中，上限函数值为0
		return h;
	else if (Value(m,e,l)*Value(m,e,h) < 0) //求解成功
		return mid;
	else //初始或求解过程中，上下限函数值同号
		return -1; //求解失败
}


//设计一款控制台窗口游戏（在规定步数内找到藏匿于‘#’阵的中的‘$’，游戏成功）

void Init_Map(char map[][5], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] ='#';
}//生成显示界面（‘#’阵，不含‘$’）（玩家可见）

void Print_Map(char map[][5], int m, int n) 
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}//输出显示界面

//对所选位置进行试探并逐步简化游戏
int Try_Map(char map[][5],int m,int n,int i, int j, int w, int v)
{
	if (i == w && j == v)
	{
		map[i - 1][j - 1] = '$';
		Print_Map(map, m, n);
		return 1;
	} //找到，输出含‘$’界面，结束试探

	map[i-1][j-1] = '-'; //未找到，将试探位置置‘-’
	int p, q;
	for (p = 0; p < m; p++) //简化游戏（纵向），将部分无‘$’位置置‘-’
	{
		if (v <= j) //‘$’在左
			for (q = j ; q < n; q++)
				map[p][q] = '-';
		else        //‘$’在右
			for (q = 0; q < j - 1; q++)
				map[p][q] = '-';
	}
	for (q = 0; q < n; q++) //简化游戏（横向），将部分无‘$’位置置‘-’
	{
		if (w <= i ) //‘$’在上
			for (p = i; p < m; p++)
				map[p][q] = '-';
		else         //‘$’在下
			for (p = 0; p < i - 1; p++)
				map[p][q] = '-';		
    }
	Print_Map(map, m, n); 
	return 0;//输出简化后界面，结束试探
}
//进行游戏（在规定步数内找到藏匿于‘#’阵的中的‘$’，游戏成功）
int Play(char map[][5], int m, int  n, int  stp)
{
	Init_Map(map, m, n); //生成显示界面（‘#’阵，不含‘$’）（玩家可见）
	srand((unsigned)time(NULL));
	int w =1+ rand() % m;
	int v =1+rand() % n; //生成两个在1~5范围内的数，[w,v]表示‘$’所在位置
	int i, j; //供玩家输入,[i,j]表示选择位置
	cout << "-------Game Start!-------" << endl << "Find the '$' hidden in these '#'" << endl;
	Print_Map(map, m, n); //输出初始界面
	while (stp) //当步数不为0
	{
		cout << "Now you have " << stp << "chances. " << endl; //提示所剩步数
		cout << "Choose line :" << endl;
		cin >> i;
		cout << "Choose column :" << endl;
		cin >> j; //要求玩家输入位置进行试探
		if (Try_Map(map, m, n, i, j, w, v)) //调用试探函数
		{
			cout << "Winning!" << endl;
			return 1;
		} //找到
		else stp--; //未找到
	}
	cout << "Game Over!" << endl; //所有步数用尽仍未找到
	return 0;
}

//异常处理例题
float checkAgeScore(int age, float score)
{
	if (age != int(age) || age < 16 || age>25)
		throw 'e';
	if (score != float(score) || score < 0 || score>5)
		throw - 1;
	
	return score * 20.0;
}

