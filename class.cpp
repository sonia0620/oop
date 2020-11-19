/*----------------------------------*
            源文件：class.cpp
			功能：Founction Definitions
*-----------------------------------*/

/*-头文件-*/
#include "CLASS.h"
#include<cmath>
#include <string>
#include <cstdlib>
#include<iostream>
using namespace std;



/*----------------------------------*
			栈类Stack
*-----------------------------------*/
//无参构造
 Stack::Stack()
{
	base = new int[MAXSIZE];
	top = base;
	stacksize = MAXSIZE;

	cout << "enter in the data:" << endl;
	while(1)
	{
		cin >> *top++;
		if (getchar()=='\n')
			break;
	}
}
 //普通构造
 Stack::Stack(int in[])
 {
	 base = new int[MAXSIZE];
	 top = base;
	 stacksize = MAXSIZE;

	 int n=sizeof(in);
	 for (int i = 0; i < n; i++)
		 *top++ = in[i];
 }
 //拷贝构造
 Stack::Stack(const Stack & stack)
 {
	 base = new int[MAXSIZE];
	 top = base;
	 stacksize = MAXSIZE;

	 int n = stack.top-stack.base;
	 for (int i = 0; i < n; i++)
		 *top++ = stack.base[i];
 }
//计算栈大小
int Stack::StackSize()
{
	return top - base;
}
//栈判空
bool Stack::StackEmpty()
{
	return top == base;
}
//栈判满
bool Stack::StackFull()
{
	return StackSize() == stacksize;
}
//入栈
bool Stack::Push(int e)
{
	if (StackFull())
		return false;
	*top++ = e;
	return true;
}
//出栈
bool Stack::Pop(int &e)
{
	if (StackEmpty())
		return false;
	e = *--top;
	return true;
}

/*----------------------------------*
			字符串类Mystring
*-----------------------------------*/
//无参构造
Mystring::Mystring()
{
	data = new char[MAXSIZE];
	cout << "enter in the string :" << endl;
	cin >> data;
}
//普通构造
Mystring::Mystring(char ch[])
{
	data = new char[MAXSIZE];

	char *p = data;
	while (*ch!= '\0')
	{
		*p++ = *ch;
		ch++;
	}
	*p = '\0';
}
//拷贝构造
Mystring::Mystring(const Mystring & string)
{
	data = new char[MAXSIZE];

	char *p =data;
	char *q = string.data;
	while (*q != '\0')
	{
		*p++ = *q;
		q++;
	}
	*p = '\0';		
}
//求串长
int Mystring::StringLength()
{
	char *p = data;
	int len = 0;
	while (*p != '\0')
	{
		len++;
		p++;
	}
	return len;
}
//反转
void Mystring::ReverseString()
{
	for (int j = 0; j <= StringLength()/2; j++)
	{
		char tmp = data[j];
		data[j] = data[StringLength() - 1 - j];
		data[StringLength() - 1 - j] = tmp;
	}
}
//増
bool Mystring::InsertString(int i,char c)
{
	if (i<1 || i>StringLength())
		return false;
	for (int j = StringLength()+1; j >= i; j--)
		data[j] = data[j-1];
	data[i-1] = c;

	return true;
}
//删
bool Mystring::DeleteString(int i)
{
	if (i<1 || i>StringLength())
		return false;
	for (int j = i-1; j <StringLength(); j++)
		data[j] = data[j + 1];

	return true;	
}
//改
bool Mystring::AlterString(int i, char c)
{
	if (i<1 || i>StringLength())
		return false;
	data[i-1] = c;

	return true;
}
//查
int Mystring::SearchString(char c)
{
	for (int i = 0; i < StringLength(); i++)
		if (data[i] == c)
			return i + 1;	
	return -1;
}
//连接
void AttachString(Mystring & a,Mystring & b)
{
	int i = a.StringLength();
	for (int j=0;j<=b.StringLength();j++)
		a.data[ i + j] = b.data[j];
}

//输出
void Mystring::Display()
{
	cout << data << endl;
}
//比较
int ComparString(Mystring & a, Mystring & b)
{
	int i = 0;
	while (i < a.StringLength() && i < b.StringLength())
	{
		if (a.data[i] != b.data[i])
			return  a.data[i] - b.data[i];
		i++;
	}
	return a.StringLength() - b.StringLength();
}


/*----------------------------------*
			三角形类Triangle
*-----------------------------------*/
//判断
bool Triangle::JudgeTriangle()
{
	return (a + b > c && a + c > b && b + c > a);
}
//周长
void Triangle::TrianglePerimeter()
{
	if (JudgeTriangle())
		cout<<"perimeter ="<< a+b+c <<endl;
	else cout<< "can't form a triangle !" << endl;	
}
//面积
void Triangle::TriangleArea()
{	
	if (JudgeTriangle())
	{
		float cos = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
		float sin = sqrt(1 - pow(cos, 2));
		cout << "area =" << a * b * sin / 2 << endl;
	}
	else cout << "can't form a triangle !" << endl;
}
//类型
void Triangle::TriangleType()
{
	if (JudgeTriangle())
	{
		if (a == b && b == c)//等边
			cout << "equilateral ";
		else if (a == b || b == c || c == a)//等腰
			cout << "equicrural ";
		else//普通
			cout << "ordinary ";

		float cos_a = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
		float cos_b = (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c);
		float cos_c = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
		float lwst = (cos_a <= cos_b && cos_a <= cos_c) ? cos_a : (cos_b <= cos_c) ? cos_b : cos_c;
		if (lwst < 0)
			cout << "obtuse triangle."<<endl<<endl;//钝角三角形
		else if (lwst == 0)
			cout << "right triangle."<<endl << endl;//直角三角形
		else
			cout << "acute triangle."<<endl << endl;//锐角三角形
	}
	else cout << "can't form a triangle !" << endl << endl;
}


/*----------------------------------*
			学生类Student
*-----------------------------------*/
//无参构造函数
Student::Student()
{
	name = new char[10];
	cout << "enter in the <name> <gender(1/0)> <num>" << endl << "<birthyear> <birthmonth> <birthday>" << endl << "<address(room/house,road/street/town/village,district/county,city,province)> <scores>" << endl;
	cin >> name >> gender >> num >> year >> month >> day >> address;
	//getline(cin,address);
	for (int i=0;i<6;i++)
		cin >> score[i];
}
//拷贝构造函数
Student::Student(const Student & student)
{
	name = new char[10];
	int i = 0;char *p = student.name;
	while (*p != '\0')
	{
		name[i++] = *p;
		p++;
	}
	name[i] = '\0';
	gender = student.gender; num = student.num; year = student.year; month = student.month; day = student.day;
	address= student.address;
	for (int j = 0; j < 6; j++)
		score[j] = student.score[j];
}
//普通构造函数
Student::Student(char *Name, bool Gender, int Num, int Year, int Month, int Day, string Address, float Score[])
{
	name = new char[10]; 
	int i = 0;
	while(*Name!='\0')
	{
		name[i++] = *Name;
		Name++;
	}
	name[i] = '\0';
	gender = Gender; num = Num; year = Year; month = Month; day = Day;
	address =Address;
	for (int j = 0; j < 6; j++)
		score[j] = Score[j];
}
//获取信息（地址为例）
void Student::GetAddress()
{
	cout << "<address> : " << address << endl;
}
//输出信息
void Student::Display()
{
	cout << "---------------------------------- Student Information ----------------------------------" << endl << endl;
	cout << "<name> <gender>  <num>   <birthday>                 <address>" << endl << " "<< name << "      " << gender << "    " << num << "  " << year << "-" << month << "-" << day << "  " << address << endl  << "<scores>" << endl;
	for (int i = 0; i < 6; i++)
		cout << score[i] << "  ";
	cout << endl << endl << "-----------------------------------------------------------------------------------------" <<endl;
	/*cout << "size of name : " << sizeof(name) << endl;
	cout << "address of name : " << &name << endl;
	cout << "size of gender : " << sizeof(gender) << endl;
	cout << "address of gender : " << &gender << endl;
	cout << "size of num : " << sizeof(num) << endl;
	cout << "address of num : " << &num << endl;
	cout << "size of year : " << sizeof(year) << endl;
	cout << "address of year : " << &year << endl;
	cout << "size of month : " << sizeof(month) << endl;
	cout << "address of month : " << &month << endl;
	cout << "size of day : " << sizeof(day) << endl;
	cout << "address of day : " << &day << endl;
	cout << "size of address : " << sizeof(address) << endl;
	cout << "address of address : " << &address << endl;
	cout << "size of score : " << sizeof(score) << endl;
	cout << "address of score : " << &score << endl;*/


}
//修改成绩
void Student::AlterScore()
{
	int subject;
	cout << "alter subject __?__,new score __?__" << endl;
	cin >> subject;
	cin >> score[subject - 1];
}


/*----------------------------------*
			点类Point
*-----------------------------------*/
void CalcuDistance(Point & M, Point & N)
{
	cout << "the distance : " << endl << sqrt(pow((M.x - N.x), 2) + pow((M.y - N.y), 2) + pow((M.z - N.z), 2)) << endl << endl;
}

