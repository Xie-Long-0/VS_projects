#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	double coef;
	int exp;
	struct Node *next;
} Poly, *PolyList;

PolyList Poly_make();			//建立多项式
int getLength(PolyList H);		//获取长度
void Poly_sort(PolyList H);			//多项式按指数排序
PolyList Poly_merge(PolyList Ha, PolyList Hb);
void Poly_print(PolyList H);		//输出多项式
void Poly_Delete(PolyList H);


#endif // POLYNOMIAL_H_
