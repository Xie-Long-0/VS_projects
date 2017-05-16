/* 本来想把stack和vector设计成仿list，
	但是用stack实在太烦了，就把它删了
	vector设计传回元素位置时本来想用iterator
	但是它不给作为函数返回值，
	只能用int代替了
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

	printf("使用list存放数据：\n");
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
	printf("添加两个数据：\n");
	Worker Nick("Nick", 10);
	Worker Angel("Angel", 16, 2333);
	s1.insert(s1.end(), Nick);
	list_iter = s1.begin();
	s1.insert(++list_iter, Angel);

	printf("使用自定义vlist存放数据：\n");
	vList s2;
	for (int i = 0; i < 5; i++)
		s2.Push_back(p[i]);
	printf("vlist当前元素个数：%d\n", s2.Size());
	while (!s2.isEmpty())
	{
		s2.Back().Display();
		s1.push_back(s2.Back());
		s2.Pop_back();
	}
	printf("将vlist合并到list后：\n");
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();

	system("pause");
	return 0;
}

