#include "SeqList.h"
#include "Sort.h"
#include "Search.h"

void InputData(SeqList &Data, int &count);

void Result(int pos);

int main()
{
	int select = 0;
	do {
		printf("\n\t\t-----����������-----\n\n");
		int count;
		SeqList List;
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
		DataType obj;
		int pos;
		printf("\n����������ݲ���\n����Ҫ���ҵ�Ԫ�أ�");
		cin >> obj;
		printf("��ѡ��\n");
		printf("\t1.˳�����\t2.�۰����\t0.�˳�\n:");
		cin >> select;
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
			break;
		}
		if (select == 0) break;
		printf("���س�������������������˳���");
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
	printf("\n�����������ܸ�����");
	cin >> count;
	Data.Create(count);
}

void Result(int pos)
{
	if (pos)
		printf("�ɹ���Ԫ��λ�ã�%d\n\n", pos);
	else
		printf("Ԫ��δ�ҵ���\n\n");
}


