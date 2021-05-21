#pragma once

#include "SeqList.h"

/**
 * @brief 顺序搜索
 * @tparam T 元素类型
 * @param Data 线性数据存储结构
 * @param e 查找元素
 * @return 元素的位置，从1开始
 *   @retval 0 未找到
*/
template<typename T>
int OrderSearch(const SeqList<T> &Data, const T &e);

/**
 * @brief 二分搜索
 * @tparam T 元素类型
 * @param Data 线性数据存储结构
 * @param e 查找元素
 * @return 元素的位置，从1开始
 *   @retval 0 未找到
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
		mid = start + (end - start) / 2;	//防止直接平均可能造成的溢位
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
