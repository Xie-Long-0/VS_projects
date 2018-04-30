#include "SeqList.h"

bool SeqList::Create(int count)
{
	if (count >= MAXSIZE)
	{
		printf("数据超过表的上限：%d 建表失败！\n\n", MAXSIZE);
		return false;
	}
	Type data;
	for (int i = 0; i < count; i++)
	{
		printf("输入第%d个数据：", i + 1);
		cin >> data;
		Push(data);
	}
	printf("\n建表成功：");
	Print();
	return true;
}

void SeqList::Push(Type e)
{
}

void SeqList::Push(DataType e)
{
	size++;
	rear++;
	_list[rear] = e;
}

DataType SeqList::list(int p)
{
	return _list[p];
}

void SeqList::Swap(int pos1, int pos2)
{
	DataType temp = _list[pos1];
	_list[pos1] = _list[pos2];
	_list[pos2] = temp;
}

void SeqList::Mod(int pos, DataType e)
{
	_list[pos] = e;
}

int SeqList::Size()
{
	return size;
}

int SeqList::i_Begin()
{
	return front;
}

int SeqList::i_End()
{
	return rear;
}

void SeqList::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << _list[i] << " ";
	}
	printf("\n");
}

