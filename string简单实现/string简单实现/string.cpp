#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace LL
{
	class string{
	public:
		//构造函数
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//赋值
		string& operator=(const string &s)
		{
			/*if (this != &s)
			{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			}*/
			if (this != &s)
			{
				string tmp(s);
				swap(_str, tmp._str);
			}
			return *this;
		}

		//析构函数
		~string()
		{
			if (_str){
				delete[]_str;
				_str = nullptr;
			}
		}

	private:
		char* _str;
	};
}

int main(){
	LL::string s1("hello");
	LL::string s2("world");
	s1 = s2;
	LL::string s3(s2);
	printf("%s\n", s1);
	printf("%s\n", s3);
	system("pause");
	return 0;
}