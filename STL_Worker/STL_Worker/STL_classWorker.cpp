#include <iostream>
#include <string>
#include <list>

#include "vList.h"
#include "sList.h"

using namespace std;

/* ���һ�������� */
class Worker
{
	string name;				//����
	int age;						//����
	double salary;				//����
public:
	Worker(string Name = "None", int Age = 0, double Salary = 0)
		{ name = Name; age = Age; salary = Salary; }
	Worker(Worker &p)
		{ name = p.name; age = p.age; salary = p.salary; }
	void setData(string Name = "None", int Age = 0, double Salary = 0)
		{ name = Name; age = Age; salary = Salary; }				//������������
	void Display();
	bool operator==(Worker p);							//����==�����
};

void Worker::Display()
{
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "���ʣ�" << salary << endl << endl;
}

bool Worker::operator==(Worker p)
{
	if (p.name == name && p.age == age &&  p.salary == salary)
		return true;
	else
		return false;
}
