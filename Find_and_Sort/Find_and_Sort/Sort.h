#pragma once

#include "SeqList.h"

/**
 * @brief ð������
 * @param Data �������ݴ洢�ṹ
*/
template<typename T>
void BubbleSort(SeqList<T> &Data);

/**
 * @brief ѡ������
 * @param Data �������ݴ洢�ṹ
*/
template<typename T>
void SelectSort(SeqList<T> &Data);

/**
 * @brief ϣ������
 * @param Data �������ݴ洢�ṹ
*/
template<typename T>
void ShellSort(SeqList<T> &Data);


template<typename T>
void BubbleSort(SeqList<T> &Data)
{
	int i, k;
	for (i = Data.size() - 1; i > 1; i--)
	{
		for (k = 0; k < i; k++)
		{
			if (Data.at(k) > Data.at(k + 1))
			{
				Data.swap(k, k + 1);
			}
		}
	}
}

template<typename T>
void SelectSort(SeqList<T> &Data)
{
	int i, k, min;
	for (i = 0; i < Data.size() - 1; i++)
	{
		min = i;
		for (k = i + 1; k < Data.size(); k++)
		{
			if (Data.at(k) < Data.at(min))
				min = k;
		}
		if (Data.at(min) == Data.at(i))
			continue;
		Data.swap(min, i);
	}
}

template<typename T>
void ShellSort(SeqList<T> &Data)
{
	T temp;
	int gap, i, k;
	for (gap = Data.size() * 0.5; gap > 0; gap *= 0.5)	//����1λ==����2
	{
		for (i = gap; i < Data.size(); i++)
		{
			temp = Data.at(i);
			for (k = i - gap; k >= 0 && Data.at(k) > temp; k -= gap)
				Data.at(k + gap) = Data.at(k);
			if (Data.at(k + gap) == temp)
				continue;
			Data.at(k + gap) = temp;
		}
	}
}
