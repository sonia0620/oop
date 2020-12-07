/*----------------------------------*
			头文件:EXERCISE.h
*-----------------------------------*/
#ifndef _EXERCISE_H_
#define _EXERCISE_H_
#include<iostream>
using namespace std;

/*----------------------------------*
		 Class Definition
*-----------------------------------*/

/*-5.2-*/
///*----------------------------------*
//			基类A
//*-----------------------------------*/
//class A
//{
//public:
//	A(int a=0)
//	{
//		x = a;
//		cout << "A : x=" << a << endl;
//	}
//protected:
//private:
//	int x;
//};
///*----------------------------------*
//            派生类B
//*-----------------------------------*/
//class B
//{
//public:
//	B(int a,int b,int c)//:a2(b),a1(a)
//	{
//		//a1.x = a; a2.x = b;
//		//a1(a);a2(b); 
//		y = c;
//		cout << "B : y=" << c << endl;
//	}
//protected:
//private:
//	A a1,a2;
//	int y;
//};


/*-5.6-*/
///*----------------------------------*
//			成员类Member
//*-----------------------------------*/
//class Member
//{
//public:
//	Member()
//	{
//		cout << "constructing Member\n";
//	}
//	~Member()
//	{
//		cout << "destructing Member\n";
//	}
//protected:
//private:
//};
///*----------------------------------*
//			基类Base
//*-----------------------------------*/
//class Base
//{
//public:
//	Base()
//	{
//		cout << "constructing Base\n";
//	}
//	~Base()
//	{
//		cout << "destructing Base\n";
//	}
//protected:
//private:
//	Member mem;
//};
///*----------------------------------*
//			继承类Derived
//*-----------------------------------*/
//class Derived:public Base
//{
//public:
//	Derived()
//	{
//		cout << "constructing Derived\n";
//	}
//	~Derived()
//	{
//		cout << "destructing Derived\n";
//	}
//protected:
//private:
//	//Member mem;
//};


/*-5.7-*/
///*----------------------------------*
//			基类Base
//*-----------------------------------*/
//class Base
//{
//public:
//	Base(int i)
//	{
//		x = i;
//		cout << "constructing Base\n";
//	}
//	void show()
//	{
//		cout << "x=" << x << endl;
//	}
//protected:
//private:
//	int x;
//};
///*----------------------------------*
//			继承类Derived
//*-----------------------------------*/
//class Derived:public Base
//{
//public:
//	Derived(int i,int j):Base(i),d(j)
//	{
//		cout << "constructing Derived\n";
//	}
//protected:
//private:
//	Base d;
//};


/*-5.12-*/
///*----------------------------------*
//			虚基类Base
//*-----------------------------------*/
//class Base
//{
//public:
//	Base(int x):a(x)
//	{
//		cout << "Base a=" << a << endl;
//	}
//	~Base()
//	{
//		cout << "destructing Base" << endl;
//	}
//protected:
//	int a;
//private:	
//};
///*----------------------------------*
//			基类Base1
//*-----------------------------------*/
//class Base1:public virtual Base
//{
//public:
//	Base1(int x,int y) :Base(y),b(x)
//	{
//		cout << "Base1 from Base a=" << a << endl;
//		cout << "Base1 b=" << b << endl;
//	}
//	~Base1()
//	{
//		cout << "destructing Base1" << endl;
//	}
//protected:
//	int b;
//private:
//};
///*----------------------------------*
//			基类Base2
//*-----------------------------------*/
//class Base2 :virtual public Base
//{
//public:
//	Base2(int x, int y) :Base(y), c(x)
//	{
//		cout << "Base2 from Base a=" << a << endl;
//		cout << "Base2 c=" << c << endl;
//	}
//	~Base2()
//	{
//		cout << "destructing Base2" << endl;
//	}
//protected:
//	int c;
//private:
//};
///*----------------------------------*
//			继承类Derived
//*-----------------------------------*/
//class Derived :public Base1, public Base2
//{
//public:
//	Derived(int x, int y) :Base1(x,y), Base2(2*x,2*y),Base(3*x)
//	{
//		//cout << "a=" << a << endl;
//		//cout << "Base::a=" << Base::a << endl;
//		cout << "Base1::a=" << Base1::a << endl;
//		cout << "Base2::a=" << Base2::a << endl; 
//		cout << "b=" << b << endl;
//		cout << "c=" << c << endl;
//		
//	}
//	~Derived()
//	{
//		cout << "constructing Derived" << endl;
//	}
//protected:
//private:
//};


/*-5.13-*/
/*----------------------------------*
			基类Base
*-----------------------------------*/
class Base
{
public:
	Base(int x):b(x)
	{}
	int getb()
	{
		return b;
	}
	virtual int getd()
	{
		return 0;
	}//定义虚函数
protected:
private:
	int b;
};
/*----------------------------------*
			继承类Derived
*-----------------------------------*/
class Derived:public Base
{
public:
	Derived(int x,int y):Base(x),d(y)
	{}
	int getd()//与基类虚函数同名的函数
	{
		return d;
	}
protected:
private:
	int d;
};












#endif