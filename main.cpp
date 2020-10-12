#define _CRT_SECURE_NO_WARNINGS

/*----------------------------------*
         学生成绩管理系统       
*-----------------------------------*/


/*-头文件-*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"score.h"


/*----------------------------------*
               主函数
*-----------------------------------*/


int main()
{
	printf("####################################\n");
	printf(" StudentPerformanceManagementSystem \n");
	printf("####################################\n");

	/*-变量初始化-*/
	int N = 0;        //学生总数
	SS *stu = NULL;   //学生（结构体）数组

	/*-读取信息-*/
	stu = ReadDataFromFile(&N);

	/*-计算总成绩-*/
	CalcuScore(stu, N);

	/*-按成绩进行排名-*/
	SortScore(stu, N);

	/*-按排名输出信息-*/
	PrintOut(stu,N);

	/*-按学号查询某个学生的成绩-*/
	FindScore(stu, N);

	/*-统计全班同学成绩的均值、标准方差，分析成绩分布-*/
	AnalyzeScore(stu, N);

	/*-释放学生数组空间-*/
	free(stu);

	system("pause");
	
	return 0;
}