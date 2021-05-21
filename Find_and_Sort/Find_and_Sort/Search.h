#pragma once

#include "SeqList.h"

/**
 * @brief ˳������
 * @tparam T Ԫ������
 * @param Data �������ݴ洢�ṹ
 * @param e ����Ԫ��
 * @return Ԫ�ص�λ�ã���1��ʼ
 *   @retval 0 δ�ҵ�
*/
template<typename T>
int OrderSearch(const SeqList<T> &Data, const T &e);

/**
 * @brief ��������
 * @tparam T Ԫ������
 * @param Data �������ݴ洢�ṹ
 * @param e ����Ԫ��
 * @return Ԫ�ص�λ�ã���1��ʼ
 *   @retval 0 δ�ҵ�
*/
template<typename T>
int BinarySearch(const SeqList<T> &Data, const T &e);


template<typename T>
int OrderSearch(const SeqList<T> &Data, const T &e)
{
	int pos = 0;
	for (int i = 0; i < Data.size(); i++)
		if (Data.at(i) == e)
			pos = i + 1;
	return pos;
}

template<typename T>
int BinarySearch(const SeqList<T> &Data, const T &e)
{
	int pos = 0;
	int mid, start = 0, end = Data.size() - 1;
	while (start <= end)
	{
		mid = start + (end - start) / 2;	//��ֱֹ��ƽ��������ɵ���λ
		if (Data.at(mid) < e)
			start = mid + 1;
		else if (Data.at(mid) > e)
			end = mid - 1;
		else
		{
			pos = mid + 1;
			break;
		}
	}
	return pos;
}
