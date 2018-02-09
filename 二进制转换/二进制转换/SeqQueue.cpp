//#include "SQtemplate.h"
//
///* 入队 */
//template<typename T>
//bool SeqQueue<T>::Push(T data)
//{
//	if (isFull())
//		return false;
//	elem[count++] = data;
//	return true;
//}
//
///* 出队 */
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
///* 读取队首元素 */
//template<typename T>
//bool SeqQueue<T>::getTop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[0];
//	return true;
//}
