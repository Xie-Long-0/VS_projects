#pragma once
#ifndef _WORKER_H_
#define _WORKER_H_

using namespace std;

class vList;

/* 设计一个工人类 */
class Worker
{
	string name;				//姓名
	int age;						//年龄
	double salary;				//工资
	static int person;			//工人总数
	int number;					//编号
public:
	Worker(const string Name = "None", int Age = 0, double Salary = 0);
	Worker(const Worker &p);
	~Worker() { person--; }
	void setData(const string Name, int Age, double Salary)
	{
		name = Name; age = Age; salary = Salary;	 number = person;				//设置数据
	}
	void Display();
	bool Equl(Worker &_Left, Worker &_Right);					//代替==重载
};

int Worker::person = 0;

Worker::Worker(const string Name, int Age, double Salary)
{
	name = Name;
	age = Age;
	salary = Salary;
	if (Name != "None" || Age != 0 || Salary != 0)
	{
		number = ++person;
		printf("已创建：\n");
		Display();
	}
	else
		number = 0;
}

Worker::Worker(const Worker & p)
{
	name = p.name;
	age = p.age;
	salary = p.salary;
	number = p.number + 1;
}

inline void Worker::Display()
{
	printf("【%d】\n", number);
	printf("姓名：%s\n", name.data());
	printf("年龄：%d\n", age);
	printf("工资：%g\n\n", salary);
}

inline bool Worker::Equl(Worker & _Left, Worker & _Right)
{
	if (_Left.name == _Right.name && _Left.age == _Right.age && _Left.salary == _Right.salary)
		return true;
	return false;
}

#endif //!_WORKER_H_
