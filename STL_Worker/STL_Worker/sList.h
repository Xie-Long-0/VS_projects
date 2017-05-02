/* ��stack������� */

#pragma once
#ifndef _SLIST_H_
#define _SLIST_H_

#include <stack>

using namespace std;

class Worker;

class sList
{
	stack<Worker> node;
public:
	sList() {}
	sList(Worker p) { node.push(p); }
	sList(int n, Worker p) { while (n--) node.push(p); }
	~sList() { while (!node.empty()) node.pop(); }
	void AddNode(Worker p);								//��ӽڵ�
	bool InsertNode(int pos, Worker p);				//����ڵ�
	bool DeleteNode(int pos);								//ɾ��ĳ���ڵ�
	bool DeleteNode(int beg, int end);					//ɾ��ĳ������Ľڵ�
	int FindNode(Worker p);									//���ҽڵ�
	bool Swap(int pos1, int pos2);						//���������ڵ�
	bool isEmpty();							//�ж��Ƿ�Ϊ��
	void Clear();									//��սڵ�
};

inline void sList::AddNode(Worker p)
{
	node.push(p);
}

bool sList::InsertNode(int pos, Worker p)
{
	return false;
}


#endif // !_SLIST_H_
