/* 用stack设计链表 */

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
	void AddNode(Worker p);								//添加节点
	bool InsertNode(int pos, Worker p);				//插入节点
	bool DeleteNode(int pos);								//删除某个节点
	bool DeleteNode(int beg, int end);					//删除某个区间的节点
	int FindNode(Worker p);									//查找节点
	bool Swap(int pos1, int pos2);						//交换两个节点
	bool isEmpty();							//判断是否为空
	void Clear();									//清空节点
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
