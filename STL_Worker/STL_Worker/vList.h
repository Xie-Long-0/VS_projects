/* ��vector������� */

#pragma once
#ifndef _VLIST_H_
#define _VLIST_H_

#include <vector>

using namespace std;

class Worker;

class vList
{
	vector<Worker> node;
public:
	vList() {}
	vList(Worker p) { node.push_back(p); }
	vList(int n, Worker p) { node.resize(n, p); }
	~vList() { node.clear(); }
	void AddNode(Worker p);								//��ӽڵ�
	bool InsertNode(int pos, Worker p);				//����ڵ�
	bool DeleteNode(int pos);								//ɾ��ĳ���ڵ�
	bool DeleteNode(int beg, int end);					//ɾ��ĳ������Ľڵ�
	int FindNode(Worker p);									//���ҽڵ�
	bool Swap(int pos1, int pos2);						//���������ڵ�
	bool isEmpty();							//�ж��Ƿ�Ϊ��
	void Clear();									//��սڵ�
};

inline void vList::AddNode(Worker p)
{
	node.push_back(p);
}

bool vList::InsertNode(int pos, Worker p)
{
	vector<Worker>::iterator iter = node.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == node.end())
			return false;
	}
	node.insert(iter, p);
	return true;
}

bool vList::DeleteNode(int pos)
{
	vector<Worker>::iterator iter = node.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == node.end())
			return false;
	}
	node.erase(iter);
	return true;
}

bool vList::DeleteNode(int beg, int end)
{
	vector<Worker>::iterator iterbeg = node.begin();
	for (int i = 0; i < beg; i++, iterbeg++)
	{
		if (iterbeg == node.end())
			return false;
	}
	vector<Worker>::iterator iterend = iterbeg;
	for (int i = beg; i < end; i++, iterend++)
	{
		if (iterend == node.end())
			return false;
	}
	node.erase(iterbeg, iterend);
	return true;
}

int vList::FindNode(Worker p)
{
	int pos, len = node.size();
	for (pos = 0; pos < len; pos++)
	{
		if (node.at(pos) == p)
			return pos;					//�����ҵ��Ľڵ�λ��
	}
	return -1;
}

inline bool vList::Swap(int pos1, int pos2)
{
	int len = node.size();
	if (pos1 > len || pos2 > len)
		return false;
	Worker p = node.at(pos1);
	node.at(pos1) = node.at(pos2);
	node.at(pos2) = p;
	return true;
}

inline bool vList::isEmpty()
{
	if (node.begin() == node.end())
		return true;
	else
		return false;
}

inline void vList::Clear()
{
	node.clear();
}


#endif // !_VLIST_H_
