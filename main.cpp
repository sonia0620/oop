/*----------------------------------*
            源文件：main.cpp
			功能：Task Realizations
*-----------------------------------*/


/*-头文件-*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include "CLASS.h"


using namespace std;

/*----------------------------------*
         Class Definition
*-----------------------------------*/
	
	


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	
	/*----------------------------------*
			    栈类Stack
	*-----------------------------------*/
	
	cout << "-------1.Class Stack-------" << endl;
	Stack S;//定义并初始化栈S
	Stack SS(S);//定义并用栈S初始化SS

	int e;

	cout << "enter in the data you want to insert :" << endl;
	cin >> e;
	SS.Push(e);//入栈

	cout << "the data in the stack :" << endl;
	while(SS.Pop(e)) 
		cout << e<<endl;//出栈
	



	/*----------------------------------*
			    字符串类Mystring
	*-----------------------------------*/
	
	cout << "-------2.Class Mystring-------" << endl;
	Mystring C;//定义并初始化C
	cout << "C is :" << endl ; C.Display();
	cout << "the length of C is :" <<C.StringLength() << endl << endl;//求串长

    char ch[10] = "abcdefg";
	Mystring CC(ch);//定义并用字符数组ch初始化CC
	cout << "CC is :" << endl ; CC.Display();
	CC.ReverseString();//反转
	cout << "after reversal , CC is :" << endl;CC.Display();

	char c; 
	int plc;

	cout << "enter in the char __ ,the place __ you want to insert :" << endl;
	cin >> c>>plc;
	CC.InsertString(plc,c);//増
	cout << "after insert , CC is :" << endl ; CC.Display();

	cout << "enter in the place __ you want to delete :" << endl;
	cin >> plc;
	CC.DeleteString(plc);//删
	cout << "after delete , CC is :" << endl ; CC.Display();
	
	
	cout << "enter in the char __ ,the place __ you want to alter :" << endl;
	cin >> c >> plc;
	CC.AlterString(plc, c);//改
	cout << "after alter , CC is :" << endl ; CC.Display();

	cout << "enter in the the char __ you want to search :" << endl;
	cin >> c;
	cout << "the place of it is :" << CC.SearchString(c)<<endl;//查

    AttachString(CC,C);//连接
	cout << "after attach C to CC , CC is :" << endl ; CC.Display();
	
	if (ComparString(CC, C) >= 1)//比较
		cout << "CC > C" << endl << endl;
	else if (ComparString(CC, C) <= -1)
		cout << "CC < C" << endl << endl;
	else cout << "CC = C" << endl << endl;
	



	/*----------------------------------*
			    三角形类Triangle
	*-----------------------------------*/
	
	cout << "-------3.Class Triangle-------" << endl;
	Triangle T;//定义并初始化T
	Triangle TT(3.0, 4.0, 5.0);//定义并用参数初始化TT
	T.TrianglePerimeter();//周长
	T.TriangleArea();//面积
	T.TriangleType();//类型
	//TT.TriangleType();
	


	/*----------------------------------*
			    学生类Student
	*-----------------------------------*/
	
	cout << "-------4.Class Student-------" << endl;

	float Score[6] = { 98,87,76,65,54,43 };
	Student Stu1((char*)"Tom",1,201911996789,2000,8,31,"1,University Road,Guyunhu Street,Changqing District,Jinan City,Shandong Province",Score);//定义并初始化Stu1
	//cout << "size of Stu1 : " << sizeof(Stu1) << endl;
	//cout << "address of Stu1: " << &Stu1 << endl;
	Stu1.Display(); cout << endl << endl;

	Student Stu2(Stu1);//定义并初始化Stu2
	//cout << "size of Stu2 : " << sizeof(Stu2) << endl;
	//cout << "address of Stu2 : " << &Stu2 << endl;
	Stu2.Display(); cout << endl << endl;

	//Student Stu3(Stu2);//定义并初始化Stu3
	//cout << "size of Stu3 : " << sizeof(Stu3) << endl;
	//cout << "address of Stu3 : " << &Stu3 << endl;
	//Stu3.Display(); cout << endl << endl;

	//Student Stu4(Stu3);//定义并初始化Stu3
	//cout << "size of Stu4 : " << sizeof(Stu4) << endl;
	//cout << "address of Stu4 : " << &Stu4 << endl;
	//Stu4.Display(); cout << endl << endl;



	//SStu.GetAddress();//获取地址
	Stu2.AlterScore();Stu2.Display();//修改成绩
	
	/*----------------------------------*
				点类Point
	*-----------------------------------*/
    
	cout << "-------5.Class Point-------" << endl;
	Point A;//定义并初始化A
	cout << "A"; A.DisplayPoint(); cout << endl;
	
	Point B(0,0,0); //定义并用参数初始化B
	cout << "B"; B.DisplayPoint();
	B.AlterPoint();//修改
	cout << "B"; B.DisplayPoint(); cout << endl;

	cout << "A --- B ";
	CalcuDistance(A, B);//距离
    


	/*----------------------------------*
			    线段类Segment
    *-----------------------------------*/
    
	cout << "-------6.Class Segment-------" << endl;
	Segment L;
	cout << "the endpoints :" << endl;
	L.DisplayEndpoint();
	L.CalcuLength();
    
    

	system("pause");
	
	return 0;
}