#include <iostream>
#include <string>
#include "KMP.h"

using namespace std;

vector<int> getNext(const string sub);
int kmpSearch(const string src, const string sub);

int main()
{
	string T = "ABCBABCABDABCD";
	string S = "ABCAB";
	cout << "Text：" << T << endl;
	cout << "Sub：" << S << endl;
	int result = kmpSearch(T, S);
	if (result == False)
		cout << "找不到该字符串" << endl;
	else
		cout << "该字符串第一次出现的位置是：" << result + 1 << endl;
	system("pause");
	return 0;
}