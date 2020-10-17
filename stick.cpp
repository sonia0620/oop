/*----------------------------------*
     源文件 :stick.cpp    
	 功能 :Function Definitions 
*-----------------------------------*/

/*-头文件-*/
#include"STICK.h"
#include<cmath>
#include <cstdlib>
#include<iostream>;
using namespace std;


/*-从m根木棍中选择三根组成周长尽可能长的三角形，输出最大周长及所选木棍长度-*/
void Max_C(float *l, int m)
{
	float max_c = 0; //初始化最大周长
	float *elect = (float *)malloc(3 * sizeof(float));//动态开辟空间用于保存所选木棍长度
	for (int i = 0; i <= m - 3; i++) //选第一根
	{
		for (int j = i + 1; j <= m - 2; j++) //选第二根
		{
			for (int k = j + 1; k <= m - 1; k++) //选第三根
				if (l[i] + l[j] > l[k] && l[i] + l[k] > l[j] && l[j] + l[k] > l[i]) //如果三边能构成三角形
				{
					float c = l[i] + l[j] + l[k]; //计算三边构成的三角形周长
					if (c > max_c) //如果大于目前最大周长
					{
						elect[0] = l[i]; elect[1] = l[j]; elect[2] = l[k]; //保存所选木棍长度
						max_c = c; //修改最大周长
					}
				}
		}
	}

	cout << "the largest perimeter = " << max_c << endl;//输出最大周长,如果怎么选都无法构成三角形,将输出0
	if (max_c)
		cout << "elect : " << elect[0] << " , "<<elect[1] <<" , " <<elect[2] << endl;//输出所选边
	free(elect);//释放空间
}
float CalcuTri(const float *p, const float *q, const float *n)
{
	float cos = (pow(*p, 2) + pow(*q, 2) - pow(*n, 2)) / (2 * *p * *q);
	float sin = sqrt(1 - pow(cos, 2));
	float area = *p * *q*sin / 2;
	return area;

}//求面积

/*-从m根木棍中选择三根组成面积尽可能大的三角形，输出最大面积及所选木棍长度-*/
void Max_S(float *l, int m)
{
	float max_s = 0; //初始化最大面积
	float *elect = (float *)malloc(3 * sizeof(float)); //动态开辟空间用于保存所选木棍长度
	for (int i = 0; i <= m - 3; i++) //选第一根
	{
		for (int j = i + 1; j <= m - 2; j++) //选第二根
		{
			for (int k = j + 1; k <= m - 1; k++) //选第三根
				if (l[i] + l[j] > l[k] && l[i] + l[k] > l[j] && l[j] + l[k] > l[i]) //如果三边能构成三角形
				{
					float s = CalcuTri(&l[i], &l[j], &l[k]); //计算三边构成的三角形面积
					if (s > max_s) //如果大于目前最大面积
					{
						elect[0] = l[i]; elect[1] = l[j]; elect[2] = l[k]; //保存所选木棍长度
						max_s = s; //修改最大面积
					}
				}
		}
	}
	cout << "the largest area = " << max_s << endl; //输出最大面积,如果怎么选都无法构成三角形,将输出0
	if (max_s)
		cout << "elect : " << elect[0] <<" , "<< elect[1] << " , "<<elect[2] << endl;//输出所选边
	free(elect);//释放空间
}