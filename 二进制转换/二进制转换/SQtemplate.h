#ifndef SQTEMPLATE_H_
#define SQTEMPLATE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX_SIZE 512

using namespace std;

/* 队列类模板 */
template<typename T>
class SeqQueue
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	SeqQueue() { count = 0; }
	~SeqQueue() {}
	int Length() { return count; }			//元素个数
	bool isEmpty() { return count <= 0; }		//是否为空
	bool isFull() { return count >= MAX_SIZE; }		//是否为满
	void Init() { count = 0; }			//初始化
	bool Push(T &data);				//入队
	bool Pop(T &data);				//出队
	bool getTop(T &data);			//读取队首元素
};


/* 堆栈类模板 */
template<typename T>
class SeqStack
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	SeqStack() { count = 0; }
	~SeqStack() {}
	int Length() { return count; }			//元素个数
	bool isEmpty() { return count <= 0; }		//是否为空
	bool isFull() { return count >= MAX_SIZE; }		//是否为满
	void Init() { count = 0; }			//初始化
	bool Push(T &data);				//入栈
	bool Pop(T &data);				//出栈
	bool getTop(T &data);			//读取栈顶元素
};


//分离文件编译失败。。。


//#include "SQtemplate.h"

/* 入队 */
template<typename T>
bool SeqQueue<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* 出队 */
template<typename T>
bool SeqQueue<T>::Pop(T &data)
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
bool SeqQueue<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[0];
	return true;
}



//#include "SQtemplate.h"

/* 入栈 */
template<typename T>
bool SeqStack<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* 出栈 */
template<typename T>
bool SeqStack<T>::Pop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[--count];
	return true;
}

/* 读取栈顶元素 */
template<typename T>
bool SeqStack<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[count - 1];
	return true;
}




#endif // !SQTEMPLATE_H_
