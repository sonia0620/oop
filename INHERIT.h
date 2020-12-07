/*----------------------------------*
			头文件:INHERIT.h
*-----------------------------------*/
#ifndef _INHERIT_H_
#define _INHERIT_H_
#include<iostream>
using namespace std;

/*----------------------------------*
		 Class Definition
*-----------------------------------*/


/*----------------------------------*
            基类base
*-----------------------------------*/
class base
{
public:
	int a;
	base(int aa,int bb,int cc):a(aa),b(bb),c(cc)
	{
		count++; 
		cout << "constructing base." << endl;
	}//构造函数
	~base()
	{
		count--;
		cout << "destructing base." << endl;
	}//析构函数
	void print()
	{
		cout << "base: a=" << a << ",b=" << b << ",c=" << c << endl;
	}//输出类的数据成员函数
	static int statistic()
	{
		return count;
	}//统计类对象创建个数的函数
protected:
	int b;
private:
	int c; 
	static int count;
};

/*----------------------------------*
            派生类derived1
*-----------------------------------*/
class derived1:public base
{
public:
	derived1(int p,int q,int r):base(p,q,r)
	{
		cout << "constructing derived1." << endl;
	}
	~derived1()
	{
		cout << "destructing derived1." << endl;
	}
	void show1()
	{
		cout << "base1: a=" << a;
		cout << ",b=" << b << endl;
		//cout << ",c=" << c << endl;//私有数据继承但不可见
	}
protected:
private:
};

/*----------------------------------*
			派生类derived2
*-----------------------------------*/
class derived2 :protected base
{
public:
	derived2(int p, int q, int r) :base(p, q, r)
	{
		cout << "constructing derived2." << endl;
	}
	~derived2()
	{
		cout << "destructing derived2." << endl;
	}
	void show2()
	{
		cout << "base2: a=" << a;
		cout << ",b=" << b << endl;
		//cout << ",c=" << c << endl;//私有数据继承但不可见
	}
protected:
private:
};

/*----------------------------------*
			派生类derived3
*-----------------------------------*/
class derived3 :private base
{
public:
	derived3(int p, int q, int r) :base(p, q, r)
	{
		cout << "constructing derived3." << endl;
	}
	~derived3()
	{
		cout << "destructing derived3." << endl;
	}
	void show3()
	{
		cout << "base3: a=" << a;
		cout << ",b=" << b << endl;
		//cout << ",c=" << c << endl;//私有数据继承但不可见
	}
protected:
private:
};




/*----------------------------------*
            二维平面点类Location
*-----------------------------------*/
class Location
{
public:
	float x, y;
	Location()
	{
		cout << "x=___" << endl; cin >> x;	cout << "y=___" << endl; cin >> y;
	}
	void move()//实现移动该类对象的坐标位置
	{
		cout << "change x=___" << endl; cin >> x;	cout << "change y=___" << endl; cin >> y;
	}
	void show()//输出当前类对象的信息
	{
		cout << "location: (" << x << "," << y << ")" << endl;
	}
protected:
private:
};

/*----------------------------------*
			三维空间点类Point
*-----------------------------------*/
class Point:public Location
{
public:
	float z;
	Point()//Location()
	{
		cout << "z=___" << endl; cin >> z;
	}
	void move()//实现移动该类对象的坐标位置
	{
		Location::move(); cout << "change z=___" << endl; cin >> z;
	}
	void show()//输出当前类对象的信息
	{
		cout << "location: (" << x << "," << y << "," << z << ")" << endl;
	}
protected:
private:
};

/*----------------------------------*
			球体类Sphere
*-----------------------------------*/
class Sphere:public Point  //三维空间点作为圆心
{
public:
	float r;  //半径
	Sphere()//Point()
	{
		cout << "r=___" << endl; cin >> r;
	}
	void move()//实现移动该类对象的坐标位置
	{
		Point::move(); cout << "change r=___" << endl; cin >> r;
	}
	void show()//输出当前类对象的信息
	{
		cout << "center "; Point::show(); cout << "radius: " << r << endl;
	}
protected:
private:
};


#endif