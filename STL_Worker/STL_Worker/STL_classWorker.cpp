/* 拿了书上一个例题来做
*   各种方法都用一遍   
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

/* 设计一个工人类 */
class Worker
{
	string name;				//姓名
	int age;						//年龄
	double salary;				//工资
public:
	Worker(string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;
	}
	void setData(string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;				//重新设置数据
	}
	void Display()
	{
		cout << "姓名：" << name << endl;
		cout << "年龄：" << age << endl;
		cout << "工资：" << salary << endl << endl;
	}
};

class vList
{
	vector<Worker> worker;
public:
	vList() {}
	vList(Worker &p) { worker.at(0) = p; }
	vList(int n) { worker.reserve(n); }
	~vList() { worker.clear(); }
	
};

