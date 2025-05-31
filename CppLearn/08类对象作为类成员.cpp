#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//c++类中的成员可以是另一个类的对象
//我们称该成员为 对象成员

//类对象作为类成员


//当其他类的对象作为本类成员 构造时候先构造类对象 再构造自身 
//先有其他类再有自身

//析构的顺序与构造相反


class phone08 {
	//名字
public:
	phone08(string pName) {
		cout << "phone的构造函数调用" << endl;
		PName = pName;
	}
	~phone08() {
		cout << "phone的析构函数调用" << endl;
	}
	
	string PName;
};


class person08 {

public:
	//phone08 Phone = pName//隐式转换法
	person08(string name, string pName):Name(name), Phone(pName) {

		cout << "person的构造函数调用" << endl;
	}
	~person08() {
		cout << "person的析构函数调用" << endl;
	}
	//姓名
	string Name;
	//手机  也是一个类
	phone08 Phone;


};
void test08() {
	person08 p("老鸭鸭", "一坨屎");
	
	cout << p.Name << "拿着" << p.Phone.PName << endl;

}
int main0801(void) {

	test08();



	system("pause");
	return 0;
}