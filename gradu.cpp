/*----------------------------------*
         头文件：gradu.cpp
	     功能：Founction definitions
*-----------------------------------*/

#include "GRADU.h"
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

Graduate::Graduate() : university("Shandong Normal University")
{
	cout << "enter in the information ( except for the university ) : " << endl;
	//cin  >> name >> gender >> id >> score >> research >> tutor;
	getline(cin, name);
	cin >> gender >> id >> score; cin.ignore();
	getline(cin, research ); 
	getline(cin, tutor ); 
	total += score; number++;
}

Graduate::Graduate(string n, bool g, int d, double s, string r, string t) : university("Shandong Normal University")
{
	name = n; gender = g; id = d; score = s; research = r; tutor = t;
	total += score; number++;
}

Graduate::Graduate(const Graduate & g) : university("Shandong Normal University")
{
	name = g.name; gender = g.gender; id = g.id; score = g.score; research = g.research; tutor = g.tutor;
	total += score; number++;
}

double Graduate::total;
int Graduate::number;//初始化


void Graduate::Print()
{
	cout << endl << "==================  the information ( general print )  ==================" << endl;
	cout << "Name:" << name << "  Gender:" << gender << "  Id:" << id << endl << "Score:" << score << "  Research:" << research << "  Tutor:" << tutor << endl << "University:" << university << endl;
}

void Graduate::Print() const
{
	cout << endl << "==================  the information ( const print )  ==================" << endl;
	cout << "Name:" << name << "  Gender:" << gender << "  Id:" << id << endl << "Score:" << score << "  Research:" << research << "  Tutor:" << tutor << endl << "University:" << university << endl;
}

void Graduate::GetAver()
{
	cout << endl << "==================  the average score of " << number << " graduates  ==================" << endl;
	cout << double(total / number) << endl;
}

void GetGrade(const Graduate &g)
{
	//（90 分以上输出 A, 80 - 89 分输出 B，70 - 79 分输出 C, 60 - 69 分输出 D，60 分以下输出 E)
	switch (int(g.score/10))
	{
	case 10:
	case 9: cout << " A  " << endl; break;
	case 8: cout << " B  " << endl; break;
	case 7: cout << " C  " << endl; break;
	case 6: cout << " D  " << endl; break;
	case 5: 
	case 4:
	case 3:
	case 2:
	case 1:
	case 0: cout << " E  " << endl; break;
	default:cout << " ERROR!  " << endl; break;
	}
}

