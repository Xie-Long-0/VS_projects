#include <iostream>
#include <string>
#include <cmath>
#include "SQtemplate.h"

using namespace std;


/*** 二进制转十进制 ***/
void Bin2Dec(string num)
{
	if (num[0] == '-')
	{
		num = num.erase(0, 1);
		putchar('-');
	}
	while (num[0] == '0')
		num = num.erase(0, 1);

	Queue<char> intbit;								//整数二进制位存放队列
	Queue<char> floatbit;							//小数二进制位存放队列
	char getint;
	char getfloat;
	long integer = 0;
	long decimal = 0;

	while (num[0] != '.' && !num.empty())
	{
		getint = num[0];
		if (intbit.Push(getint))					//存入每个二进制位
		{
			if (getint != '0' && getint != '1')
			{
				cout << "非法二进制数！" << endl;
				return;
			}
			num = num.erase(0, 1);
		}
		else
			break;
	}
	while (!intbit.isEmpty())
	{
		if (intbit.Pop(getint))						//转换成十进制
			integer += (getint - '0')*pow(2, intbit.Length());
		else
			break;
	}
	cout << integer;

	if (num[0] == '.')
	{
		putchar('.');										//如果没有小数则结束
		num = num.erase(0, 1);
	}
	else
		return;

	while (!num.empty())
	{
		getfloat = num[0];							//存入每个小数位
		if (floatbit.Push(getfloat))
		{
			if (getint != '0' && getint != '1')
			{
				cout << "非法二进制数！" << endl;
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
		if (floatbit.Pop(getfloat))				//用整数模仿小数
			if (getfloat == '1')
				decimal += state*pow(10, floatbit.Length());
	}
	cout << decimal;
}


/*** 十进制转二进制 ***/
void Dec2Bin(double num)
{
	if (num < 0)
	{
		num = -num;
		putchar('-');
	}
	long integer  = (long)num;				//整数部分
	double decimal = num - integer;		//小数部分
	Stack<int> mod;								//整数取余存放堆栈
	Queue<int> bit;									//小数取进位存放队列
	int getmod;
	int getbit;

	while (integer > 0)
	{
		getmod = integer % 2;
		if (mod.Push(getmod))					//除2取余
			integer /= 2;
		else
			break;
	}
	while (!mod.isEmpty())
	{
		if (mod.Pop(getmod))					//倒序输出
			cout << getmod;
		else
			break;
	}

	while (decimal >= 1E-6)
	{
		getbit = (int)(decimal * 2);
		if (bit.Push(getbit))						//乘2取进位
			decimal = decimal * 2 - (int)(decimal * 2);
		else
			break;
	}
	if (bit.isEmpty())
		return;
	putchar('.');
	while (!bit.isEmpty())
	{
		if (bit.Pop(getbit))							//顺序输出
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





