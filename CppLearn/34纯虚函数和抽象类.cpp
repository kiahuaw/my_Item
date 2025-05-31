#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
在多态中 通常父类中虚函数的实现是毫无意义的 主要都是调用子类重写的内容

因此可以将虚函数改为纯虚函数

语法
virtual 返回值类型 函数名(参数列表) = 0;

当类中有了纯虚函数 这个类成为抽象类

抽象类特点 ：
	1、无法实例化对象
	2、子类必须重写抽象类中的纯虚函数 否则也属于抽象类

*/
using namespace std;

class base34 {
public:
	//纯虚函数
	virtual void func() = 0;


};

class son :public base34 {
public:
	virtual void func() {
		cout << "func() 调用" << endl;
	}

};
void test34() {
	//base34 b;//报错  抽象类无法实例化对象
	//new base34;//!ok
	//son s;//子类没重写父类中的纯虚函数
	son s;//子类必须重写父类中的纯虚函数 否则无法实例化对象
	base34* sb = new son;
	sb->func();
	delete sb;

	


}
int main3401(void) {
	test34();


	return 0;
}
