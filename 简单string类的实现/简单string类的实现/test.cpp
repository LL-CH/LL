#include<iostream>

using namespace std;
class String{
public:
	String(const char* str=""){
		if (nullptr == str)
			_str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	String& operator=(const String& s){
		if(this != &s){
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}

	~String(){
		if(_str){
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main(){
	char* s = "abcd";
	String s1(s);

	printf("%s\n", s1);
	system("pause");
	return 0;
}