/* 本来想把vector设计成仿list， */


#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

#include "vlist.h"

using namespace std;

/* 设计一个工人类 */
class Worker
{
	string name;				//姓名
	int age;						//年龄
	double salary;				//工资
	static int person;			//工人总数
	int number;					//编号
public:
	Worker(const string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;
		if (Name!="None" || Age != 0 || Salary != 0)
		{
			number = ++person;
			printf("已创建：\n");
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
		name = Name; age = Age; salary = Salary;	 number = person;		//设置数据
	}
	void Display();
	bool operator==(const Worker &p);						//重载==运算符
};

int Worker::person = 0;

inline void Worker::Display()
{
	printf("【%d】\n", number);
	printf("姓名：%s\n", name.data());
	printf("年龄：%d\n", age);
	printf("工资：%g\n\n", salary);
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

	printf("使用list存放数据：\n");
	list<Worker> s1;
	for (int i = 0; i < 5; i++)
	{
		s1.push_back(p[i]);
		s1.back().Display();
	}
	printf("删除Alice后：\n");
	list<Worker>::iterator list_iter = s1.begin();
	Worker Alice = p[0];
	s1.remove(Alice);
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();
	printf("添加两个数据：\n");
	Worker Nick("Nick", 10);
	Worker Angel("Angel", 16, 2333);
	s1.insert(s1.end(), Nick);
	list_iter = s1.begin();
	s1.insert(++list_iter, Angel);

	printf("使用vector存放数据：\n");
	vector<Worker> s2;
	for (int i = 0; i < 5; i++)
		s2.push_back(p[i]);
	printf("vector当前容量：%d\n", s2.capacity());
	printf("vector当前元素个数：%d\n", s2.size());
	while (!s2.empty())
	{
		s2.back().Display();
		s1.push_back(s2.back());
		s2.pop_back();
	}
	printf("将list与vector合并后：\n");
	for (list_iter = s1.begin(); list_iter != s1.end(); list_iter++)
		list_iter->Display();

	system("pause");
	return 0;
}