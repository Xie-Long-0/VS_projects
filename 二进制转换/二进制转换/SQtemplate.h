#pragma once
#ifndef _SQTEMPLATE_H_
#define _SQTEMPLATE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 1024


//************************************//
/* 队列类模板 */
template<typename T>
class Queue
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	Queue() { count = 0; }
	~Queue() {}
	int Length() { return count; }			//元素个数
	bool isEmpty() { return count <= 0; }		//是否为空
	bool isFull() { return count >= MAX_SIZE; }		//是否为满
	void Init() { count = 0; }			//初始化
	bool Push(T &data);				//入队
	bool Pop(T &data);				//出队
	bool getTop(T &data);			//读取队首元素

};

/* 入队 */
template<typename T>
bool Queue<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* 出队 */
template<typename T>
bool Queue<T>::Pop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[0];
	count--;
	for (int i = 0; i < count; i++)
		elem[i] = elem[i + 1];
	return true;
}

/* 读取队首元素 */
template<typename T>
bool Queue<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[0];
	return true;
}
//*****************************//


//*****************************//
/* 堆栈类模板 */
template<typename T>
class Stack
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	Stack() { count = 0; }
	~Stack() {}
	int Length() { return count; }			//元素个数
	bool isEmpty() { return count <= 0; }		//是否为空
	bool isFull() { return count >= MAX_SIZE; }		//是否为满
	void Init() { count = 0; }			//初始化
	bool Push(T &data);				//入栈
	bool Pop(T &data);				//出栈
	bool getTop(T &data);			//读取栈顶元素

};

/* 入栈 */
template<typename T>
bool Stack<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* 出栈 */
template<typename T>
bool Stack<T>::Pop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[--count];
	return true;
}

/* 读取栈顶元素 */
template<typename T>
bool Stack<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[count - 1];
	return true;
}
//****************************//

#endif // !_SQTEMPLATE_H_
