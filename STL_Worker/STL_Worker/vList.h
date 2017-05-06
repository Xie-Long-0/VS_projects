/* 用vector设计链表 */

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
	vList(Worker &p) { node.push_back(p); }
	vList(const int n, Worker &p) { node.resize(n, p); }
	~vList() { node.clear(); }
	void AddNode(Worker &p);							//添加节点
	void InsertNode(const int pos, Worker &p);	//插入节点
	const int DeleteNode(const int pos);						//删除某个节点
	const int DeleteNode(int beg, int end);					//删除某个区间的节点
	const int FindNode(const Worker p);						//查找节点
	bool Swap(int pos1, int pos2);						//交换两个节点
	void Swap(vList &_Right);			//交换两个容器全部元素
	bool isEmpty();							//判断是否为空
	void Clear();									//清空节点
};

inline void vList::AddNode(Worker &p)
{
	node.push_back(p);
}

void vList::InsertNode(const int pos, Worker &p)
{
	vector<Worker>::iterator iter = node.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == node.end())
			return;
	}
	node.insert(iter, p);
}

const int vList::DeleteNode(int pos)
{
	vector<Worker>::iterator iter = node.begin();
	for (int i = 0; i < pos; i++, iter++)
	{
		if (iter == node.end())
			return -1;
	}
	node.erase(iter);
	return pos;
}

const int vList::DeleteNode(int beg, int end)
{
	vector<Worker>::iterator iterbeg = node.begin();
	for (int i = 0; i < beg; i++, iterbeg++)
	{
		if (iterbeg == node.end())
			return -1;
	}
	vector<Worker>::iterator iterend = iterbeg;
	for (int i = beg; i < end; i++, iterend++)
	{
		if (iterend == node.end())
			return -1;
	}
	node.erase(iterbeg, iterend);
	return end;
}

const int vList::FindNode(const Worker p)
{
	int pos, len = node.size();
	for (pos = 0; pos < len; pos++)
	{
		if (node.at(pos) == p)
			return pos;					//返回找到的节点位置
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

inline void vList::Swap(vList & _Right)
{
	node.swap(_Right.node);
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
