//#include "SQtemplate.h"
//
///* ��� */
//template<typename T>
//bool SeqQueue<T>::Push(T data)
//{
//	if (isFull())
//		return false;
//	elem[count++] = data;
//	return true;
//}
//
///* ���� */
//template<typename T>
//bool SeqQueue<T>::Pop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[0];
//	count--;
//	for (int i = 0; i < count; i++)
//		elem[i] = elem[i + 1];
//	return true;
//}
//
///* ��ȡ����Ԫ�� */
//template<typename T>
//bool SeqQueue<T>::getTop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[0];
//	return true;
//}
