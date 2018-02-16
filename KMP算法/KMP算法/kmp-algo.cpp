#include "kmp-algo.h"

/* ���Next */
vector<int> getNext(string sub)
{
	int len = sub.length();
	vector<int> next;
	next.resize(len, 0);					//��resize��ʼ��
	int k = 0;
	for (int i = 1; i < len; i++)
	{
		while (k > 0 && sub.at(k) != sub.at(i))					//
			k = next.at(k);										//����ǰ�����Ϣ����ƥ��
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

/* �����ַ��� */
int kmpSearch(string src, string sub)
{														//srcԴ�ַ�����sub���ַ���
	int srclen = src.length();			//Դ������
	int sublen = sub.length();			//�Ӵ�����
	vector<int> next = getNext(sub);

	int current = 0;				//��ǰλ��
	int subpos = 0;				//�Ӵ�ƫ��λ��
	while (current < srclen)
	{
		while (subpos < sublen)
		{
			subpos++;
			if (src.at(current + subpos - 1) == sub.at(subpos - 1))
			{
				if (subpos == sublen)
					return current + 1;								//�ҵ�ƥ���ַ���
			}
			else
			{
				current += subpos - next.at(subpos - 1);			//�ַ���ƥ�������
																	//cout << subpos;
				subpos = 0;
				break;
			}
		}
	}
	return False;					//����ʧ��
}
