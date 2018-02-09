//#include "SQtemplate.h"
//
///* 入栈 */
//template<typename T>
//bool SeqStack<T>::Push(T data)
//{
//	if (isFull())
//		return false;
//	elem[count++] = data;
//	return true;
//}
//
///* 出栈 */
//template<typename T>
//bool SeqStack<T>::Pop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[--count];
//	return true;
//}
//
///* 读取栈顶元素 */
//template<typename T>
//bool SeqStack<T>::getTop(T data)
//{
//	if (isEmpty())
//		return false;
//	data = elem[count - 1];
//	return true;
//}
