#ifndef SQTEMPLATE_H_
#define SQTEMPLATE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX_SIZE 512

using namespace std;

/* ������ģ�� */
template<typename T>
class SeqQueue
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	SeqQueue() { count = 0; }
	~SeqQueue() {}
	int Length() { return count; }			//Ԫ�ظ���
	bool isEmpty() { return count <= 0; }		//�Ƿ�Ϊ��
	bool isFull() { return count >= MAX_SIZE; }		//�Ƿ�Ϊ��
	void Init() { count = 0; }			//��ʼ��
	bool Push(T &data);				//���
	bool Pop(T &data);				//����
	bool getTop(T &data);			//��ȡ����Ԫ��
};


/* ��ջ��ģ�� */
template<typename T>
class SeqStack
{
private:
	T elem[MAX_SIZE];
	int count;
public:
	SeqStack() { count = 0; }
	~SeqStack() {}
	int Length() { return count; }			//Ԫ�ظ���
	bool isEmpty() { return count <= 0; }		//�Ƿ�Ϊ��
	bool isFull() { return count >= MAX_SIZE; }		//�Ƿ�Ϊ��
	void Init() { count = 0; }			//��ʼ��
	bool Push(T &data);				//��ջ
	bool Pop(T &data);				//��ջ
	bool getTop(T &data);			//��ȡջ��Ԫ��
};


//�����ļ�����ʧ�ܡ�����


//#include "SQtemplate.h"

/* ��� */
template<typename T>
bool SeqQueue<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* ���� */
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

/* ��ȡ����Ԫ�� */
template<typename T>
bool SeqQueue<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[0];
	return true;
}



//#include "SQtemplate.h"

/* ��ջ */
template<typename T>
bool SeqStack<T>::Push(T &data)
{
	if (isFull())
		return false;
	elem[count++] = data;
	return true;
}

/* ��ջ */
template<typename T>
bool SeqStack<T>::Pop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[--count];
	return true;
}

/* ��ȡջ��Ԫ�� */
template<typename T>
bool SeqStack<T>::getTop(T &data)
{
	if (isEmpty())
		return false;
	data = elem[count - 1];
	return true;
}




#endif // !SQTEMPLATE_H_
