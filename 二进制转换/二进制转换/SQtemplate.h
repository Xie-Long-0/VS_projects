#pragma once
#ifndef _SQTEMPLATE_H_
#define _SQTEMPLATE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 1024


//************************************//
/* ������ģ�� */
template<typename T>
class Queue
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	Queue() { count = 0; }
	~Queue() {}
	int Length() { return count; }			//Ԫ�ظ���
	bool isEmpty() { return count <= 0; }		//�Ƿ�Ϊ��
	bool isFull() { return count >= MAX_SIZE; }		//�Ƿ�Ϊ��
	void Init() { count = 0; }			//��ʼ��
	bool Push(T &data);				//���
	bool Pop(T &data);				//����
	bool getTop(T &data);			//��ȡ����Ԫ��

};

/* ��� */
template<typename T>
bool Queue<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* ���� */
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

/* ��ȡ����Ԫ�� */
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
/* ��ջ��ģ�� */
template<typename T>
class Stack
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	Stack() { count = 0; }
	~Stack() {}
	int Length() { return count; }			//Ԫ�ظ���
	bool isEmpty() { return count <= 0; }		//�Ƿ�Ϊ��
	bool isFull() { return count >= MAX_SIZE; }		//�Ƿ�Ϊ��
	void Init() { count = 0; }			//��ʼ��
	bool Push(T &data);				//��ջ
	bool Pop(T &data);				//��ջ
	bool getTop(T &data);			//��ȡջ��Ԫ��

};

/* ��ջ */
template<typename T>
bool Stack<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* ��ջ */
template<typename T>
bool Stack<T>::Pop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[--count];
	return true;
}

/* ��ȡջ��Ԫ�� */
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
