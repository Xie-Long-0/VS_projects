/* �������stack��vector��Ƴɷ�list��
	������stackʵ��̫���ˣ��Ͱ���ɾ��
	vector��ƴ���Ԫ��λ��ʱ��������iterator
	������������Ϊ��������ֵ��
	ֻ����int������
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

#include "Worker.h"
#include "vlist.h"

using namespace std;

int main()
{
	Worker p[5] = { {"Alice", 20, 5000}, {"Jack", 25, 8200}, {"Steve", 18, 2000} };
	p[3] = p[0];

	printf("ʹ��list������ݣ�\n");
	list<Worker> s1;
	for (int i = 0; i < 5; i++)
	{
		s1.push_back(p[i]);
		s1.back().Display();
	}
	list<Worker>::iterator list_iter = s1.begin();
	//Worker Alice = p[0];
	//s1.remove(Alice);
	//for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
	//	list_iter->Display();
	printf("����������ݣ�\n");
	Worker Nick("Nick", 10);
	Worker Angel("Angel", 16, 2333);
	s1.insert(s1.end(), Nick);
	list_iter = s1.begin();
	s1.insert(++list_iter, Angel);

	printf("ʹ���Զ���vlist������ݣ�\n");
	vList s2;
	for (int i = 0; i < 5; i++)
		s2.Push_back(p[i]);
	printf("vlist��ǰԪ�ظ�����%d\n", s2.Size());
	while (!s2.isEmpty())
	{
		s2.Back().Display();
		s1.push_back(s2.Back());
		s2.Pop_back();
	}
	printf("��vlist�ϲ���list��\n");
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();

	system("pause");
	return 0;
}

