//#include "SQtemplate.h"
//
///* ��ջ */
//template<typename T>
//bool SeqStack<T>::Push(T data)
//{
//	if (isFull())
//		return false;
//	elem[count++] = data;
//	return true;
//}
//
///* ��ջ */
//template<typename T>
//bool SeqStack<T>::Pop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[--count];
//	return true;
//}
//
///* ��ȡջ��Ԫ�� */
//template<typename T>
//bool SeqStack<T>::getTop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[count - 1];
//	return true;
//}
