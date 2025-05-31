#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
using namespace std;
/*
主要探究继承中同名的静态成员在子类对象上如何进行访问

静态成员和非静态成员出现同名 处理方式一致
	访问子类同名成员 直接访问
	访问父类同名成员 加作用域

//同名静态成员处理方式和非静态处理方式一样 只不过有两种访问的方式
1、通过对象 2、通过类名
*/
class base29 {
public:
	
	static void func() {
		cout << "base - static void func()" << endl;
	}
	static int m_a;
};
int base29::m_a = 100;

class son29 :public base29 {
public:
	static void func() {
		cout << "son - static void func()" << endl;
	}
	static int m_a;
};
int son29::m_a = 200;

//同名静态成员属性
void test2901() {
	//1、通过对象方式访问
	cout << "通过对象访问" << endl;
	son29 s;
	cout << "son -> m_a = " << s.m_a << endl;
	cout << "base-> m_a = " << s.base29::m_a << endl;

	//2、通过类名访问
	cout << "通过类名访问" << endl;
	cout << "son -> m_a = " << son29::m_a << endl;
	//第一个::代表通过类名方式访问   第二个::代表访问父类作用域下
	cout << "base-> m_a = " <<son29::base29::m_a << endl;
}
//同名静态成员函数
void test2902() {
	//1、通过对象访问
	son29 s;
	s.func();
	s.base29::func();
	//2、通过类名方式访问
	son29 s1;
	son29::func();
	son29::base29::func();
}

int main2901(void) {
	//test2901();
	test2902();


	return 0;
}
