/* ��������һ����������
*   ���ַ�������һ��   
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

/* ���һ�������� */
class Worker
{
	string name;				//����
	int age;						//����
	double salary;				//����
public:
	Worker(string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;
	}
	void setData(string Name = "None", int Age = 0, double Salary = 0)
	{
		name = Name; age = Age; salary = Salary;				//������������
	}
	void Display()
	{
		cout << "������" << name << endl;
		cout << "���䣺" << age << endl;
		cout << "���ʣ�" << salary << endl << endl;
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

