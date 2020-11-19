/*----------------------------------*
            头文件：CLASS.h
*-----------------------------------*/

#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
using namespace std;
const int MAXSIZE = 20;

/*----------------------------------*
            栈类Stack
*-----------------------------------*/
class Stack
{
private:
	int *base;
	int *top;
	int stacksize;
public:
	Stack();//无参构造函数
	Stack(int in[]);//普通构造函数,in为一整型数组
	Stack(const Stack& stack);//拷贝构造函数
	~Stack()
	{
		delete[]base;
	}//析构函数
	bool StackEmpty();//栈判空
	bool StackFull();//栈判满
	int StackSize();//计算栈的大小
	bool Push(int);//入栈
	bool Pop(int &);//出栈	
}; 

/*----------------------------------*
            字符串类Mystring
*-----------------------------------*/
class Mystring
{
private:
	char *data;
public:
	Mystring();//无参构造函数
	Mystring(char ch[]);//普通构造函数,ch为一字符数组
	Mystring(const Mystring& string);//拷贝构造函数
	~Mystring()
	{
		delete []data;
	}//析构函数
	int StringLength();//求串长
	void ReverseString();//反转
	bool InsertString(int,char);//増
	bool DeleteString(int);//删
	bool AlterString(int, char);//改
	int SearchString(char);//查
	friend void AttachString(Mystring &, Mystring &);//连接
	friend int ComparString(Mystring &, Mystring &);//比较
	void Display();//输出
};

/*----------------------------------*
            三角形类Triangle
*-----------------------------------*/
class Triangle
{
private:
	float a, b, c;
public:
	Triangle()
	{
		cout<<"enter in a,b,c :"<<endl;
		cin >> a >> b >> c;
	}//无参构造函数
	Triangle(float aa, float bb, float cc):a(aa),b(bb),c(cc)
	{
		//a = aa; b = bb; c = cc;
	}//普通构造函数
	Triangle(const Triangle& triangle)
	{
		a = triangle.a; b = triangle.b; c = triangle.c;
	}//拷贝构造函数
	~Triangle(){}//析构函数
	bool JudgeTriangle();//判断
	void TrianglePerimeter();//周长
	void TriangleArea();//面积
	void TriangleType();//类型
};


/*----------------------------------*
            学生类Student
*-----------------------------------*/
class Student
{
private:
	char* name;//姓名
	bool gender;//性别
	int num;//学号
	int year, month, day;//出生日期
	string address;//家庭地址
	float score[6];//六科成绩
public:
	Student();//无参构造函数
	Student(char [], bool, int, int, int, int, string, float []);//普通构造函数
	Student(const Student& student);//拷贝构造函数
	~Student()
	{
		delete[]name; 
	}//析构函数
	void GetAddress();//获取信息（地址为例）
	void Display();//输出信息
	void AlterScore();//修改成绩
};



/*----------------------------------*
            点类Point
*-----------------------------------*/
class Point
{
private:
	float x, y, z;//横纵竖坐标
public:
	Point()
	{
		cout << "point : x __?__ ,y __?__,z __?__" << endl;
		cin >> x >> y >> z;
	}//无参构造函数
	Point(float xx, float yy, float zz)
	{
		x = xx; y = yy; z = zz;
	}//普通构造函数
	Point(const Point &point)
	{
		x = point.x; y = point.y; z = point.z;
	}//普通构造函数
	~Point(){}//析构函数
	void DisplayPoint()
	{
		cout << " ( " << x << " , " << y << " , " << z << ")" << endl;
	}//输出坐标
	void AlterPoint()
	{
		cout << "alter point : x __?__ ,y __?__ ,z __?__" << endl;
		cin >> x >> y >> z;
	}
	//修改坐标
	friend void CalcuDistance(Point &, Point &);//友元函数求距离
	friend class Segment;//友元类

};
/*----------------------------------*
            线段类Segment
*-----------------------------------*/
class Segment
{
public:
	Point origin , end;//端点
	Segment(){};//构造函数
	~Segment(){};//析构函数
	void CalcuLength()
	{
		CalcuDistance(origin, end);
	}//求线段长度
	void DisplayEndpoint()
	{
		origin.DisplayPoint();
		end.DisplayPoint();
	}//输出端点
};

#endif