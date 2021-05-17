#include "kmp.h"
#include <string.h>

#ifdef __cplusplus
#include <iostream>
using std::string;
#endif // !__cplusplus

/* ���Next */
int GetNext(const char sub[], int next[], int nlen)
{
	int len = strlen(sub);
	if (nlen < len + 4)
		return -1;

	next[0] = next[1] = 0;

	int k = 0, i = 0;
	for (i = 1; i < len; i++)
	{
		while (k > 0 && sub[k] != sub[i])		//�����Ǻ����㷨
			k = next[k];						//����ǰ�����Ϣ����ƥ��

		if (sub[k] == sub[i])
			k++;

		next[i] = k;
	}
	return k;
}

int kmp_search(const char strSrc[], const char strSub[])
{
	int srcLen = strlen(strSrc);			//Դ�ַ�������
	int subLen = strlen(strSub);			//���ַ�������
	if (srcLen < subLen)
		return -1;

	int next[MAX_LEN] = { 0 };
	if (GetNext(strSub, next, MAX_LEN) < 0)
		return -1;

	int current = 0;			//��ǰλ��
	int subPos = 0;				//�Ӵ�ƫ��λ��
	while (current < srcLen)
	{
		while (subPos < subLen)
		{
			subPos++;
			if (strSrc[current + subPos - 1] == strSub[subPos - 1])
			{
				if (subPos == subLen)
					return current;			//�ҵ�ƥ���ַ����������±�
			}
			else
			{
				current += subPos - next[subPos - 1];	//�ַ���ƥ�������
				subPos = 0;
				break;
			}
		}
	}
	return -1;		//����ʧ��
}

#ifdef __cplusplus
int kmp_search(const string &strSrc, const string &strSub)
{
	// std::cout << "[Info] Compiled in C++" << std::endl;
	return kmp_search(strSrc.c_str(), strSub.c_str());
}
#endif
