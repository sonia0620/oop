#define _CRT_SECURE_NO_WARNINGS
/*-----------------------------------------*
        源文件:score.cpp
	    功能：Function Definitions
*------------------------------------------*/

/*-头文件-*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SCORE.h"

/*-函数定义-*/

//1.1手动输入学生信息(暂时不用)
void ReadData(SS stu[], int N)
{
	printf("请依次输入各位学生的：学号，姓名，平时成绩，实验成绩，期末成绩\n");
	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生\n", i + 1);
		scanf("%s %s %f %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyscore, &stu[i].experiscore, &stu[i].finalscore);
		printf("\n");
	}
	printf("-----信息录入完毕！-----\n");
}



//1.2从文件里读取学生信息
SS* ReadDataFromFile(int *N)
{
	printf("\n\n-----step1: read information from the file-----\n\n");
	SS *stu;     //开辟数组空间，用以存储学生信息
	FILE *fp = NULL;
	int count = 0;

	fp=fopen("data.txt", "r");//打开文件

	//1.2.1获取学生数目
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);//函数原型为int fscanf(文件指针，格式控制字符串，参数表列)
		*N = count;
	}
	else
	{
		printf("fail to open the information file.\n");
	}
	printf("the number of the students is %d\n", count);

	//1.2.2为学生信息分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));

	//1.2.3依次读取学生信息
	while (!feof(fp))
	{
		for (int i=0;i<*N;i++)
		{
		fscanf(fp, "%s", &stu[i].number);//函数原型为int fscanf(文件指针，格式控制字符串，参数表列,读取长度)
		fscanf(fp, "%s",&stu[i].name);
		fscanf(fp, "%f",&stu[i].dailyscore);
		fscanf(fp, "%f",&stu[i].experiscore);
		fscanf(fp, "%f",&stu[i].finalscore);
		
		}

	}//若文件未结束，继续读取

	fclose(fp);//关闭文件

	return stu;
}




//2分别计算每个学生的总成绩
void CalcuScore(SS *stu, int N)
{
	printf("\n\n-----step2: calculate the students' generalscore-----\n\n");

	for (int i = 0; i < N; i++)
	{
		stu[i].generalscore = 0.2*stu[i].dailyscore + 0.2*stu[i].experiscore + 0.6*stu[i].finalscore;
	}
}

//3根据总成绩进行排名
int Cmp_BigtoSmall(const void *a,const void *b)
{
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);

	if ((*aa).generalscore < (*bb).generalscore)
		return 1;
	else if ((*aa).generalscore > (*bb).generalscore)
		return -1;
	else return 0;
}
void SortScore(SS stu[], int N)
{
	qsort(&(stu[0]), N, sizeof(stu[0]), Cmp_BigtoSmall);//参数分别表示：开始排序的地址、参与排序的元素数目、单个元素大小、比较函数
}

//4按规定格式输出学生信息
void PrintOut(SS stu[], int N)
{
	printf("\n\n-----step3: output the students' information according to ranking of the general score-----\n\n");
	for (int i=0;i<N;i++)
	{
		printf("%s %s %4.2f %4.2f %4.2f %4.2f", stu[i].number,stu[i].name, stu[i].dailyscore,stu[i].experiscore,stu[i].finalscore,stu[i].generalscore);
		printf("\n");

	}
	
}

//5按学号查询某个学生的成绩
void FindScore(SS stu[],int N)
{
	char number_need[20];
	int i = 0;
	int flag = 0;
    printf("\n\n-----step4: input a number to inquire the student's score-----\n\n");
	scanf("%s", &number_need);
	for (i=0;i<N;i++)
		if (strcmp(stu[i].number, number_need) == 0)
		{
			flag = 1;
			break;
		}
	if (flag)
		printf("the student you want to inquire :\n%s %s %4.2f %4.2f %4.2f %4.2f", stu[i].number, stu[i].name, stu[i].dailyscore, stu[i].experiscore, stu[i].finalscore, stu[i].generalscore);
	else
		printf("do not find !!!\n");
}

//6统计全班同学成绩的均值、标准方差，分析成绩分布
float GetMean(SS stu[], int N)
{
	float num = 0;
	for (int i=0;i<N;i++)
	{
		num += stu[i].generalscore;
	}
	return num / N;
}
float GetStd_dev(SS stu[], int N)
{
	float mean = GetMean(stu, N);
	float variance = 0;
	for (int i=0;i<N;i++)
	{
		variance += pow((stu[i].generalscore - mean), 2)*(1.0 / N);
	}
	return sqrt(variance);
}
void AnalyDistri(SS stu[], int N)
{
	float mean = GetMean(stu, N);
	int superior = 0;
	int	inferior = 0;
	for (int i = 0; i < N; i++)
	{
		if (stu[i].generalscore >= mean)
			superior++;
		else
			inferior++;
	}
	printf("%4.2f%% of the students scored above average , while %4.2f%% of the students scored below average\n", 100.0*superior/N,100.0*inferior/N);
}
void AnalyzeScore(SS stu[], int N)
{
	printf("\n\n-----step5: count the mean and standard deviation of the whole class and analyze the distribution of performance-----\n\n");
	printf("the mean is : %4.2f\nthe standard deviation is : %4.2f\n", GetMean(stu, N),GetStd_dev(stu, N));
	AnalyDistri(stu, N);
}

