/* ��vector������� */

#pragma once
#ifndef _VLIST_H_
#define _VLIST_H_

#include <vector>

using namespace std;

class Worker;

class vList
{
	vector<Worker> elem;
	unsigned int size;
public:
	vList() { Init(); }
	vList(Worker &p) { Init(); elem.push_back(p); }
	vList(const int n, Worker &p) { Init(n); elem.resize(n, p); }
	~vList() { elem.clear(); }
	void Init();						//��ʼ��
	void Init(int n);
	void Push_front(Worker &p);						//�ڱ�ͷ���Ԫ��
	void Push_back(Worker &p);						//����β���Ԫ��
	void InsertNode(const int pos, Worker &p);			//����Ԫ��
	const int DeleteNode(const int pos);						//ɾ��ĳ��Ԫ��
	const int DeleteNode(int beg, int end);					//ɾ��ĳ�������Ԫ��
	const int FindNode(Worker p);						//����Ԫ��
	void Swap(vList &_Right);			//������������ȫ��Ԫ��
	Worker &Front();							//���ص�һ��Ԫ��
	Worker &Back();							//�������һ��Ԫ��
	void Pop_front();							//ɾ����һ��Ԫ��
	void Pop_back();							//ɾ�����һ��Ԫ��
	const int Size();							//����Ԫ�ظ���
	bool isEmpty();							//�ж��Ƿ�Ϊ��
	void Clear();									//���Ԫ��
};

inline void vList::Init()
{
	size = 0;
}

inline void vList::Init(int n)
{
	size = n;
}

inline void vList::Push_front(Worker & p)
{
	elem.insert(elem.begin(), p);
}

inline void vList::Push_back(Worker &p)
{
	elem.push_back(p);
}

void vList::InsertNode(const int pos, Worker &p)
{
	vector<Worker>::iterator iter = elem.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == elem.end())
			return;
	}
	elem.insert(iter, p);
}

const int vList::DeleteNode(int pos)
{
	vector<Worker>::iterator iter = elem.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == elem.end())
			return -1;
	}
	elem.erase(iter);
	return pos;
}

const int vList::DeleteNode(int beg, int end)
{
	vector<Worker>::iterator iterbeg = elem.begin();
	for (int i = 0; i < beg; i++, iterbeg++)
	{
		if (iterbeg == elem.end())
			return -1;
	}
	vector<Worker>::iterator iterend = iterbeg;
	for (int i = beg; i < end; i++, iterend++)
	{
		if (iterend == elem.end())
			return -1;
	}
	elem.erase(iterbeg, iterend);
	return end;
}

const int vList::FindNode(Worker p)
{
	Worker temp = p;
	int pos, len = elem.size();
	for (pos = 0; pos < len; pos++)
	{
		if (temp.Equl(p, elem.at(pos)))
			return pos;					//�����ҵ���Ԫ��λ��
	}
	return -1;
}

inline void vList::Swap(vList & _Right)
{
	elem.swap(_Right.elem);
}

inline Worker & vList::Front()
{
	return elem.front();
}

inline Worker & vList::Back()
{
	return elem.back();
}

inline void vList::Pop_front()
{
	elem.erase(elem.begin());
}

inline void vList::Pop_back()
{
	elem.pop_back();
}

inline const int vList::Size()
{
	return size;
}

inline bool vList::isEmpty()
{
	if (elem.begin() == elem.end())
		return true;
	else
		return false;
}

inline void vList::Clear()
{
	elem.clear();
}


#endif // !_VLIST_H_
