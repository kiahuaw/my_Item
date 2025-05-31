#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
静态成员函数
		所有对象共享一个函数
		静态成员函数只能访问静态成员变量
*/
class person {
public:
	//静态成员函数  有访问权限的  
	static void func() {
		m_a = 200;//静态成员函数可以访问静态成员变量
		//m_b = 100;静态成员函数 不可以访问 非静态成员变量
		//无法区分到底m_b到底是哪个对象的
		cout << "static void func()  d diaoyong " << endl;

	}
	static int m_a;
	int m_b;//fei
private:
	static void func02() {
		cout << "void func02()" << endl;

	}


};
int person::m_a = 100;
void test1001() {
	//1、通过对象访问
	person p;
	p.func();
	//2、通过类名访问
	person::func();
	//person::func02();类外不可访问到私有的静态成员函数
}
int main1001(void) {
	test1001();

	return 0;
}