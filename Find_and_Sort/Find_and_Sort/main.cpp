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
		printf("\n\t\t-----����������-----\n\n");
		int count = 0;
		SeqList<DataType> List;
		InputData(List, count);
		printf("����Ա�����������򣩣���ѡ��\n");
		printf("\t1.ð������\t2.ѡ������\t3.ϣ������\t0.�˳�\n:");
		cin >> select;
		switch (select)
		{
		case 0: break;
		case 1:
			printf("\n����ð������\n");
			BubbleSort(List);
			break;
		case 2:
			printf("\n����ѡ������\n");
			SelectSort(List);
			break;
		case 3:
			printf("\n����ϣ������\n");
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
			printf("��ѡ��\n");
			printf("\t1.˳�����\t2.�۰����\t0.�˳�\n:");
			cin >> select;

			if (select == 1 || select == 2)
			{
				printf("\n����Ҫ���ҵ�Ԫ�أ�");
				cin >> obj;
			}

			switch (select)
			{
			case 0: break;
			case 1:
				printf("\n˳����ң�");
				pos = OrderSearch(List, obj);
				Result(pos);
				break;
			case 2:
				printf("\n�۰���ң�");
				pos = BinarySearch(List, obj);
				Result(pos);
				break;
			default:
				select = 0;
				break;
			}
		} while (select != 0);
		printf("����Y������������������˳���");
		cin >> ch;
		if (ch[0] != 'y' && ch[0] != 'Y') break;
	}
	printf("Exiting...\n");
	return 0;
}

template<typename T>
void InputData(SeqList<T> &Data, int &count)
{
	printf("\n�����������ܸ�����");
	cin >> count;
	printf("�������ݣ�\n");
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
		printf("�ɹ���Ԫ��λ�ã�%d\n\n", pos);
	else
		printf("Ԫ��δ�ҵ���\n\n");
}
