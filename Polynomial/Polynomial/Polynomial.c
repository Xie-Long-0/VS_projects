#include "Polynomial.h"

PolyList Poly_make()
{
	PolyList H, L = (PolyList)malloc(sizeof(Poly));
	if (L == NULL)
	{
		printf("�����ʼ��ʧ�ܣ��ѽ�������...\n");
		exit(1);
	}
	L->coef = 0;
	L->exp = 0;
	L->next = NULL;
	H = L;
	printf("�������������ʽ��ϵ����ָ������ʽΪ x,p ���� 0,0����\n");
	printf("�����һ�");
	double x = 0;
	int p = 0;
	while (scanf("%lf%*c%d", &x, &p) != 2)
	{
		char cbuff[16];
		fgets(cbuff, 15, stdin);
		printf("�Ƿ���ʽ�����������루x,p����");
	}
	while (!(x==0 && p==0))
	{
		L->next = (PolyList)malloc(sizeof(Poly));
		if (L->next == NULL)
		{
			printf("��������ռ�ʧ�ܣ��ѽ�������...");
			Poly_Destroy(H);
			exit(1);
		}
		L = L->next;
		L->coef = x;
		L->exp = p;
		L->next = NULL;
		printf("�������룺");
		while (scanf("%lf%*c%d", &x, &p) != 2)
		{
			char cbuff[16];
			fgets(cbuff, 15, stdin);
			printf("�Ƿ���ʽ�����������루x,p����");
		}
	}
	Poly_sort(H);
	printf("����ʽ������ɣ�\n");
	Poly_print(H);
	return H;
}

int getLength(PolyList H)
{
	int length = 0;
	for (PolyList P = H->next; P != NULL; length++)
		P = P->next;
	return length;
}

void Poly_sort(PolyList H)
{
	for (PolyList L; H->next!=NULL; H=H->next)
	{
		for (L=H->next; L->next!=NULL; L=L->next)
		{
			if (L->next->exp < H->next->exp)
			{
				int p = H->next->exp;
				H->next->exp = L->next->exp;
				L->next->exp = p;
				double x = H->next->coef;
				H->next->coef = L->next->coef;
				L->next->coef = x;
			}
		}
	}
}

PolyList Poly_merge(PolyList Ha, PolyList Hb)
{
	PolyList H = Ha, L = Hb;
	Ha = Ha->next;
	Hb = Hb->next;
	free(L);
	L = H;
	while (Ha != NULL && Hb != NULL)
	{
		if (Ha->exp < Hb->exp)
		{
			L->next = Ha;
			L = L->next;
			Ha = Ha->next;
		}
		else if (Ha->exp == Hb->exp)		//ָ�����ʱ
		{
			if (Ha->coef + Hb->coef == 0)
			{
				PolyList P = Ha;
				Ha = Ha->next;
				free(P);
				P = Hb;
				Hb = Hb->next;
				free(P);
			}
			else
			{
				Ha->coef += Hb->coef;
				L->next = Ha;
				L = L->next;
				Ha = Ha->next;
				PolyList P = Hb;
				Hb = Hb->next;
				free(P);
			}
		}
		else
		{
			L->next = Hb;
			L = L->next;
			Hb = Hb->next;
		}
	}
	if (Ha != NULL)
		L->next = Ha;
	else if (Hb != NULL)
		L->next = Hb;
	return H;
}

void Poly_print(PolyList H)
{
	if (H->next == NULL)
	{
		printf("����ʽΪ�գ�\n\n");
		return;
	}
	H = H->next;
	if (H->exp == 0)
		printf("%g", H->coef);
	else
		printf("%gx^%d", H->coef, H->exp);
	for (H=H->next; H != NULL; H=H->next)
		printf("%+gx^%d", H->coef, H->exp);
	printf("\n\n");
}

void Poly_Destroy(PolyList H)
{
	H = H->next;
	PolyList P = H;
	while (P != NULL)
	{
		H = H->next;
		free(P);
		P = H;
	}
}

