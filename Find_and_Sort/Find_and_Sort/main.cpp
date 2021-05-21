#include <iostream>
#include <string>
#include "SeqList.h"
#include "Sort.h"
#include "Search.h"

using std::cin;
using std::string;

using DataType = double;

template<typename T>
void InputData(SeqList<T> &Data, int &count);

template<typename T>
void Print(const SeqList<T> &data);

void Result(int pos);

int main(int args, char *argv[])
{
	int select = 0;
	string ch;
	while (1)
	{
		printf("\n\t\t-----查找与排序-----\n\n");
		int count = 0;
		SeqList<DataType> List;
		InputData(List, count);
		printf("下面对表进行排序（升序），请选择：\n");
		printf("\t1.冒泡排序\t2.选择排序\t3.希尔排序\t0.退出\n:");
		cin >> select;
		switch (select)
		{
		case 0: break;
		case 1:
			printf("\n进行冒泡排序：\n");
			BubbleSort(List);
			break;
		case 2:
			printf("\n进行选择排序：\n");
			SelectSort(List);
			break;
		case 3:
			printf("\n进行希尔排序：\n");
			ShellSort(List);
			break;
		default:
			break;
		}
		if (select == 0) break;
		Print(List);
		DataType obj;
		int pos = 0;
		do
		{
			printf("请选择：\n");
			printf("\t1.顺序查找\t2.折半查找\t0.退出\n:");
			cin >> select;

			if (select == 1 || select == 2)
			{
				printf("\n输入要查找的元素：");
				cin >> obj;
			}

			switch (select)
			{
			case 0: break;
			case 1:
				printf("\n顺序查找：");
				pos = OrderSearch(List, obj);
				Result(pos);
				break;
			case 2:
				printf("\n折半查找：");
				pos = BinarySearch(List, obj);
				Result(pos);
				break;
			default:
				select = 0;
				break;
			}
		} while (select != 0);
		printf("输入Y继续，输入其它命令将退出：");
		cin >> ch;
		if (ch[0] != 'y' && ch[0] != 'Y') break;
	}
	printf("Exiting...\n");
	return 0;
}

template<typename T>
void InputData(SeqList<T> &Data, int &count)
{
	printf("\n请输入数据总个数：");
	cin >> count;
	printf("输入数据：\n");
	T tmp = T();
	for (int i = 0; i < count; i++)
	{
		cin >> tmp;
		Data.push_back(tmp);
	}
	Print(Data);
}

template<typename T>
void Print(const SeqList<T> &data)
{
	printf("[ ");
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data.at(i) << " ";
	}
	printf("] size: %d\n", data.size());
}

void Result(int pos)
{
	if (pos > 0)
		printf("成功！元素位置：%d\n\n", pos);
	else
		printf("元素未找到！\n\n");
}
