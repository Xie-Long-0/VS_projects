#ifndef SEQLIST_H_
#define SEQLIST_H_

#include <stdio.h>
#include <iostream>

#define MAXSIZE 64
typedef int Type;

using namespace std;

class SeqList
{
	Type _list[MAXSIZE];
	int size;
	int front;
	int rear;

public:
	SeqList() { Init(); }
	void Init()
	{
		size = 0;
		front = 0;
		rear = -1;
		memset(_list, 0, MAXSIZE);
		printf("\n���ѳ�ʼ��.\n\n");
	}
	bool Create(int count);			//����
	void Push(Type e);
	Type list(int p);			//���ر��е�p��Ԫ��
	void Swap(int pos1, int pos2);	//��������Ԫ��
	void Mod(int pos, Type e);	//�޸�posλ�õ�Ԫ��
	int Size();
	int i_Begin();
	int i_End();
	void Print();
	~SeqList() {};
};


#endif  //!SEQLIST_H_
