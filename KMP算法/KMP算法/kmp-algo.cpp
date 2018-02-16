#include "kmp-algo.h"

/* 设计Next */
vector<int> getNext(string sub)
{
	int len = sub.length();
	vector<int> next;
	next.resize(len, 0);					//用resize初始化
	int k = 0;
	for (int i = 1; i < len; i++)
	{
		while (k > 0 && sub.at(k) != sub.at(i))					//
			k = next.at(k);										//利用前面的信息进行匹配
		if (sub.at(k) == sub.at(i))
			k++;
		next.at(i) = k;
	}
	/*
	for (k = 0; k < len; k++)
	cout << next.at(k);
	cout << endl;
	*/
	return next;
}

/* 搜索字符串 */
int kmpSearch(string src, string sub)
{														//src源字符串，sub子字符串
	int srclen = src.length();			//源串长度
	int sublen = sub.length();			//子串长度
	vector<int> next = getNext(sub);

	int current = 0;				//当前位置
	int subpos = 0;				//子串偏移位置
	while (current < srclen)
	{
		while (subpos < sublen)
		{
			subpos++;
			if (src.at(current + subpos - 1) == sub.at(subpos - 1))
			{
				if (subpos == sublen)
					return current + 1;								//找到匹配字符串
			}
			else
			{
				current += subpos - next.at(subpos - 1);			//字符不匹配则后移
																	//cout << subpos;
				subpos = 0;
				break;
			}
		}
	}
	return False;					//查找失败
}
