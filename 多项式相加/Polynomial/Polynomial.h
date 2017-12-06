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

PolyList Poly_make();			//��������ʽ
int getLength(PolyList H);		//��ȡ����
void Poly_sort(PolyList H);			//����ʽ��ָ������
PolyList Poly_merge(PolyList Ha, PolyList Hb);
void Poly_print(PolyList H);		//�������ʽ
void Poly_Delete(PolyList H);


#endif // POLYNOMIAL_H_
