/* 用vector设计链表 */

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
	void Init();						//初始化
	void Init(int n);
	void Push_front(Worker &p);						//在表头添加元素
	void Push_back(Worker &p);						//在链尾添加元素
	void InsertNode(const int pos, Worker &p);			//插入元素
	const int DeleteNode(const int pos);						//删除某个元素
	const int DeleteNode(int beg, int end);					//删除某个区间的元素
	const int FindNode(Worker p);						//查找元素
	void Swap(vList &_Right);			//交换两个容器全部元素
	Worker &Front();							//返回第一个元素
	Worker &Back();							//返回最后一个元素
	void Pop_front();							//删除第一个元素
	void Pop_back();							//删除最后一个元素
	const int Size();							//返回元素个数
	bool isEmpty();							//判断是否为空
	void Clear();									//清空元素
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
			return pos;					//返回找到的元素位置
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
