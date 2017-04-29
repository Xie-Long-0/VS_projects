#include <iostream>
#include <string>
#include <cmath>
#include "SQtemplate.h"

using namespace std;


/*** ������תʮ���� ***/
void Bin2Dec(string num)
{
	if (num[0] == '-')
	{
		num = num.erase(0, 1);
		putchar('-');
	}
	while (num[0] == '0')
		num = num.erase(0, 1);

	Queue<char> intbit;								//����������λ��Ŷ���
	Queue<char> floatbit;							//С��������λ��Ŷ���
	char getint;
	char getfloat;
	long integer = 0;
	long decimal = 0;

	while (num[0] != '.' && !num.empty())
	{
		getint = num[0];
		if (intbit.Push(getint))					//����ÿ��������λ
		{
			if (getint != '0' && getint != '1')
			{
				cout << "�Ƿ�����������" << endl;
				return;
			}
			num = num.erase(0, 1);
		}
		else
			break;
	}
	while (!intbit.isEmpty())
	{
		if (intbit.Pop(getint))						//ת����ʮ����
			integer += (getint - '0')*pow(2, intbit.Length());
		else
			break;
	}
	cout << integer;

	if (num[0] == '.')
	{
		putchar('.');										//���û��С�������
		num = num.erase(0, 1);
	}
	else
		return;

	while (!num.empty())
	{
		getfloat = num[0];							//����ÿ��С��λ
		if (floatbit.Push(getfloat))
		{
			if (getint != '0' && getint != '1')
			{
				cout << "�Ƿ�����������" << endl;
				return;
			}
			num = num.erase(0, 1);
		}
		else
			break;
	}
	decimal = 0;
	long state = 1;
	while (!floatbit.isEmpty())
	{
		state *= 5;
		if (floatbit.Pop(getfloat))				//������ģ��С��
			if (getfloat == '1')
				decimal += state*pow(10, floatbit.Length());
	}
	cout << decimal;
}


/*** ʮ����ת������ ***/
void Dec2Bin(double num)
{
	if (num < 0)
	{
		num = -num;
		putchar('-');
	}
	long integer  = (long)num;				//��������
	double decimal = num - integer;		//С������
	Stack<int> mod;								//����ȡ���Ŷ�ջ
	Queue<int> bit;									//С��ȡ��λ��Ŷ���
	int getmod;
	int getbit;

	while (integer > 0)
	{
		getmod = integer % 2;
		if (mod.Push(getmod))					//��2ȡ��
			integer /= 2;
		else
			break;
	}
	while (!mod.isEmpty())
	{
		if (mod.Pop(getmod))					//�������
			cout << getmod;
		else
			break;
	}

	while (decimal >= 1E-6)
	{
		getbit = (int)(decimal * 2);
		if (bit.Push(getbit))						//��2ȡ��λ
			decimal = decimal * 2 - (int)(decimal * 2);
		else
			break;
	}
	if (bit.isEmpty())
		return;
	putchar('.');
	while (!bit.isEmpty())
	{
		if (bit.Pop(getbit))							//˳�����
			cout << getbit;
		else
			break;
	}
}



int main()
{
	string bin = "11100.1001";
	double dec = 28.5625;
	//cin >> dec;
	Bin2Dec(bin);
	cout << endl;
	Dec2Bin(dec);
	cout << endl;
	system("pause");
	return 0;
}





