/* �������vector��Ƴɷ�list�� */


#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

#include "vlist.h"

using namespace std;

/* ���һ�������� */
class Worker
{
	string name;				//����
	int age;						//����
	double salary;				//����
	static int person;			//��������
	int number;					//���
public:
	Worker(const string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;
		if (Name!="None" || Age != 0 || Salary != 0)
		{
			number = ++person;
			printf("�Ѵ�����\n");
			Display();
		}
		else
			number = 0;
	}
	Worker(const Worker &p)
	{
		name = p.name; age = p.age; salary = p.salary; number = p.number + 1;
	}
	~Worker()
	{
		person--;
	}
	void setData(const string Name, int Age, double Salary)
	{
		name = Name; age = Age; salary = Salary;	 number = person;		//��������
	}
	void Display();
	bool operator==(const Worker &p);						//����==�����
};

int Worker::person = 0;

inline void Worker::Display()
{
	printf("��%d��\n", number);
	printf("������%s\n", name.data());
	printf("���䣺%d\n", age);
	printf("���ʣ�%g\n\n", salary);
}

bool Worker::operator==(const Worker &p)
{
	if (p.name == name && p.age == age &&  p.salary == salary)
		return true;
	else
		return false;
}


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
	printf("ɾ��Alice��\n");
	list<Worker>::iterator list_iter = s1.begin();
	Worker Alice = p[0];
	s1.remove(Alice);
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();
	printf("����������ݣ�\n");
	Worker Nick("Nick", 10);
	Worker Angel("Angel", 16, 2333);
	s1.insert(s1.end(), Nick);
	list_iter = s1.begin();
	s1.insert(++list_iter, Angel);

	printf("ʹ��vector������ݣ�\n");
	vector<Worker> s2;
	for (int i = 0; i < 5; i++)
		s2.push_back(p[i]);
	printf("vector��ǰ������%d\n", s2.capacity());
	printf("vector��ǰԪ�ظ�����%d\n", s2.size());
	while (!s2.empty())
	{
		s2.back().Display();
		s1.push_back(s2.back());
		s2.pop_back();
	}
	printf("��list��vector�ϲ���\n");
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();

	system("pause");
	return 0;
}