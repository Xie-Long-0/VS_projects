#include "Search.h"

int OrderSearch(SeqList & Data, DataType e)
{
	int pos = 0;
	for (int i = 0; i < Data.Size(); i++)
		if (Data.list(i) == e)
			pos = i + 1;
	return pos;
}

int BinarySearch(SeqList & Data, DataType e)
{
	int pos = 0;
	int mid, start = Data.i_Begin(), end = Data.i_End();
	while (start <= end)
	{
		mid = start + (end - start) / 2;	//防止直接平均可能造成的溢位
		if (Data.list(mid) < e)
			start = mid + 1;
		else if (Data.list(mid) > e)
			end = mid - 1;
		else {
			pos = mid;
			break;
		}
	}
	return pos;
}

