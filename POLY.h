/*----------------------------------*
            头文件：POLY.h
*-----------------------------------*/
#ifndef _POLY_H_
#define _POLY_H_

/*----------------------------------*
		 Class Definition
*-----------------------------------*/



/*----------------------------------*
            整型数组类 Array
*-----------------------------------*/
class Array
{
public:
	Array();//无参构造
	Array(int [],int);//普通构造
	Array(const Array &);//拷贝构造
	~Array() 
	{
		delete[]ps;
	};//析构
	void Print();//输出对象内容
	void Alter();//修改对象元素	
	Array& operator=(const Array &); //实现对象赋值
	Array operator+(const Array &); //实现对象加（成员函数）
	friend Array operator-(const Array &,const Array &); //实现对象减（友元函数）

private:
	int* ps;
	int size;
	static const int DEFAULTSIZE;//默认数组大小，用于无参构造
};



/*----------------------------------*
            抽象基类Shapes
*-----------------------------------*/
class Shapes
{
public:
	virtual void display() = 0;//纯虚函数display()
};

/*----------------------------------*
            派生矩形类Rectangl
*-----------------------------------*/
class Rectangl:public Shapes
{
public:
	Rectangl();
	Rectangl(float,float);
	~Rectangl(){}
	void display();
	
private:
	float l, w;//长、宽
};

/*----------------------------------*
            点类Point
*-----------------------------------*/
class Point
{
public:
	Point(float,float);
	~Point(){}
	void show();

private:
	float x, y;//横、纵坐标
};

/*----------------------------------*
            派生圆类Circle
*-----------------------------------*/
class Circle:public Shapes
{
public:
	Circle();
	Circle(float, float, float);
	~Circle(){}
	void display();
	
private:
	Point c;//圆心
	float r;//半径
};


void DisplayShapes(Shapes *s); //顶层全局函数



#endif
