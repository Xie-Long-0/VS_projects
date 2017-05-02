#include <iostream>
#include <string>
#include <list>

#include "vList.h"
#include "sList.h"

using namespace std;

/* 设计一个工人类 */
class Worker
{
	string name;				//姓名
	int age;						//年龄
	double salary;				//工资
public:
	Worker(string Name = "None", int Age = 0, double Salary = 0)
		{ name = Name; age = Age; salary = Salary; }
	Worker(Worker &p)
		{ name = p.name; age = p.age; salary = p.salary; }
	void setData(string Name = "None", int Age = 0, double Salary = 0)
		{ name = Name; age = Age; salary = Salary; }				//重新设置数据
	void Display();
	bool operator==(Worker p);							//重载==运算符
};

void Worker::Display()
{
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "工资：" << salary << endl << endl;
}

bool Worker::operator==(Worker p)
{
	if (p.name == name && p.age == age &&  p.salary == salary)
		return true;
	else
		return false;
}
