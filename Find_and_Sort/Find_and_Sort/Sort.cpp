#include "Sort.h"

void BubbleSort(SeqList & Data)
{
	DataType temp;
	int i, k;
	for (i = Data.Size() - 1; i > 1; i--)
	{
		for (k = 0; k < i; k++)
		{
			if (Data.list(k) > Data.list(k + 1))
			{
				Data.Swap(k, k + 1);
				Data.Print();
			}
		}
	}
}

void SelectSort(SeqList & Data)
{
	int i, k, min;
	for (i = 0; i < Data.Size() - 1; i++)
	{
		min = i;
		for (k = i + 1; k < Data.Size(); k++)
		{
			if (Data.list(k) < Data.list(min))
				min = k;
		}
		if (Data.list(min) == Data.list(i))
			continue;
		Data.Swap(min, i);
		Data.Print();
	}
}

void ShellSort(SeqList & Data)
{
	DataType temp;
	int gap, i, k;
	for (gap = Data.Size() >> 1; gap > 0; gap >>= 1)	//”““∆1Œª==≥˝“‘2
	{
		for (i = gap; i < Data.Size(); i++)
		{
			temp = Data.list(i);
			for (k = i - gap; k >= 0 && Data.list(k) > temp; k -= gap)
				Data.Mod(k + gap, Data.list(k));
			if (Data.list(k + gap) == temp)
				continue;
			Data.Mod(k + gap, temp);
			Data.Print();
		}
	}
}

