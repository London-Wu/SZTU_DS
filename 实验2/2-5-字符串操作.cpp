#include <iostream>
#include <string>
using namespace std;

int getPos(string *strss);
string getSubStr(string *strss);

/**
 * @brief N|X|L的获取
 */
int getPos(string *strss)
{
	string command;
	cin >> command;
	int res;
	// 判断是数字还是指令
	if(command == "find"){
		
		// 继续输入并执行find
		string s = getSubStr(strss);
		int n = getPos(strss);
		res = strss[n].find(s);
		if(res == -1)
		{
			res = s.length();
		}
		//cout << "find:" << res << endl;
		
	}else if(command == "rfind"){
		
		// 继续输入并执行rfind
		string s = getSubStr(strss);
		int n = getPos(strss);
		res = strss[n].rfind(s);
		if(res == -1)
		{
			res = s.length();
		}
		
	}else{
		
		// 是个数字，直接返回
		res = stoi(command);
	}
	return res;
}

/**
 * @brief S|S1|S2的获取
 */
string getSubStr(string *strss)
{
	string command;
	string res;
	cin >> command;
	// 判断是还是指令
	if(command == "copy"){
		
		// 继续输入并执行copy
		int n = getPos(strss), x = getPos(strss), l = getPos(strss);
		res = strss[n].substr(x, l);
		//cout << "copy:" << res << endl;
		
	}else if(command == "add"){
		
		// 继续输入并执行add
		string s1 = getSubStr(strss), s2 = getSubStr(strss);
		int isdig = 1;
		// 判断是否为0 - 99999的数字
		if(s1.length()>5 || s2.length()>5)
		{
			isdig = 0;
		}
		for(auto c : s1)
		{
			if(!isdigit(c)) isdig = 0;
		}
		for(auto c : s2)
		{
			if(!isdigit(c)) isdig = 0;
		}
		
		// 进行操作
		if(isdig){
			
			int s1ti = stoi(s1);
			int s2ti = stoi(s2);
			res = to_string(s1ti+s2ti);
			
		}else{
			
			res = s1+s2;
			
		}
		
	}else{
		
		// 不是指令 直接返回
		res = command;
	}
		
	return res;
}

int main()
{
	int a;
	cin >> a;
	string *strss = new string[a+1];  // n个字符串
	string command;
	
	// 输入字符串
	for(int i=1; i<=a; i++)
	{
		cin >> strss[i];
	}
	
	// 循环 输入与处理指令
	while(1)
	{
		cin >> command;
		if(command == "over"){
			
			return 0;
			
		}else if(command == "insert"){
			
			string s = getSubStr(strss);
			int n = getPos(strss), x = getPos(strss);
			strss[n].insert(x, s);
			
		}else if(command == "reset"){
			
			string s = getSubStr(strss);
			int n = getPos(strss);
			strss[n] = s;
			
		}else if(command == "print"){
			
			int n = getPos(strss);
			cout << strss[n] << endl;
			
		}else if(command == "printall"){
			
			for(int i=1; i<=a; i++)
			{
				cout << strss[i] << endl;
			}
		}
	}
	
	delete[] strss;
}
