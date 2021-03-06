#include <iostream>
#include "kmp.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int args, char* argv[])
{
	string strSrc;
	string strSub;
	int result = -1;

	if (args >= 3)
	{
		strSrc = argv[1];
		strSub = argv[2];
	}
	else
	{
		cout << "Usage: " << argv[0] << " <source string> <substring>" << endl << endl;
		cout << "请输入字符串：";
		cin >> strSrc;
		cout << "输入要查找的字符串：";
		cin >> strSub;
	}

	result = kmp_search(strSrc, strSub);

	if (result < 0)
	{
		cout << "在字符串'" << strSrc << "'中找不到字符串'" << strSub << "'" << endl;
	}
	else
	{
		printf("字符串'%s'第一次出现在'%s'中的位置是: %d \r\n", strSub.c_str(), strSrc.c_str(), result + 1);
		int len = strSub.size();
		cout << strSrc << endl;
		for (int i = 0; i < result; i++)
			printf(" ");
		printf("^");
		for (int i = 1; i < len; i++)
			printf("~");
		cout << endl;
	}

	return 0;
}
