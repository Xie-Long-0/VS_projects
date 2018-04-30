#include "SeqList.h"
#include "Sort.h"
#include "Search.h"

void InputData(SeqList &Data, int &count);

void Result(int pos);

int main()
{
	int select = 0;
	do {
		printf("\n\t\t-----查找与排序-----\n\n");
		int count;
		SeqList List;
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
		DataType obj;
		int pos;
		printf("\n下面进行数据查找\n输入要查找的元素：");
		cin >> obj;
		printf("请选择：\n");
		printf("\t1.顺序查找\t2.折半查找\t0.退出\n:");
		cin >> select;
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
			break;
		}
		if (select == 0) break;
		printf("按回车继续，输入其它命令将退出：");
		char ch[16];
		fgets(ch, 15, stdin);
		ch[0] = getchar();
		if (ch[0] != '\n') break;
	} while (select != 0);
	printf("Exiting...\n");
	return 0;
}

void InputData(SeqList & Data, int & count)
{
	printf("\n请输入数据总个数：");
	cin >> count;
	Data.Create(count);
}

void Result(int pos)
{
	if (pos)
		printf("成功！元素位置：%d\n\n", pos);
	else
		printf("元素未找到！\n\n");
}


