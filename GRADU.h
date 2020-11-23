/*----------------------------------*
            头文件：GRADU.h
*-----------------------------------*/
#ifndef _GRADU_H_
#define _GRADU_H_
#include <string>
#include<iostream>
using namespace std;

/*----------------------------------*
		 Class Definition
*-----------------------------------*/

class Graduate
{
private:
	
	string name; bool gender; int id; double score; string research; string tutor;//姓名、性别、学号、入学成绩、研究领域、指导教师
	const string university;//学校名称（常）
	static double total;//总成绩（静）
	static int number;//总人数（静）
public:
	Graduate();
	Graduate(string, bool, int, double, string, string);
	Graduate(const Graduate &);
	~Graduate() 
	{
		total -= score; number--;
	}//三构一析
	void Print();
	void Print()const;//输出
	static void GetAver();//平均成绩
	friend void GetGrade(const Graduate &);//成绩等级
};

#endif