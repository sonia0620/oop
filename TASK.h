/*----------------------------------*
		 头文件 :TASK.h
*-----------------------------------*/

#ifndef _TASK_H_ 
#define _TASK_H

int Fib(int n);
float Value(float x);
float Dic(int m, float *e,float l,float h);

void Init_Map(char map[][5], int m, int n);
void Print_Map(char map[][5], int m, int n);
int Try_Map(char map[][5], int m, int n, int i, int j, int w, int v);
int Play(char map[][5],int m, int n, int  stp);

float checkAgeScore(int age, float score);

#endif 
