/*-----------------------------------------*
		头文件:SCORE.h		
*------------------------------------------*/


#ifndef _SCORE_H //若标识符未被定义，则进行以下编译
#define _SCORE_H 

#include <stdio.h>

/*----------------------------------*
            学生结构体设计
*-----------------------------------*/

typedef struct student
{
	char number[20];
	char name[10];
	float dailyscore;
	float experiscore;
	float finalscore;
	float generalscore;

}SS;

/*------函数说明------*/

//读取学生信息
void ReadData(SS stu[], int N);
SS* ReadDataFromFile(int *N);

//计算总成绩
void CalcuScore(SS stu[], int N);

//根据总成绩进行排名
int Cmp_BigtoSmall(const void *a, const void *b);
void SortScore(SS stu[], int N);

//按规定格式输出学生信息
void PrintOut(SS stu[], int N);

//按学号查询成绩
void FindScore(SS stu[],int N);

//统计全班同学成绩的均值、标准方差，分析成绩分布
float GetMean(SS stu[], int N);
float GetVariance(SS stu[], int N);
void AnalyDistri(SS stu[], int N);
void AnalyzeScore(SS stu[], int N);


#endif//否则不执行编译

