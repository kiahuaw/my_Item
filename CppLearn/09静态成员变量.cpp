#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//
/*
静态成员就是再成员变量和成员函数前加上关键字static  称为静态成员
静态成员分为
	静态成员变量
		所有对象共享一份数据  ==  都是指向同一个地址的数据
		在编译阶段分配内存	==
		类内声明  类外初始化  必须有一个初始值
	静态成员函数
		所有对象共享一个函数
		静态成员函数只能访问静态成员变量
	

*/
class person09 {

public:

	//int m_a;//非静态
	static int m_a;//静态  所有对象共享的
	

	//静态成员变量也是有访问权限的
	//
private:
	static int m_b;

};

int person09::m_a = 100;//类外初始化
int person09::m_b = 200;

void test0901() {

	person09 p;

	cout << p.m_a << endl;

	person09 p2;
	p2.m_a = 200;
	cout << p.m_a << endl;
}
void test0902() {
	//静态变量成员 不属于某个对象上 因为所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1通过对象访问
	person09 p;
	cout << p.m_a << endl;



	//2通过类名访问   可以通过类名加其域下的名称进行访问
	cout << person09::m_a << endl;


	//cout << person09::m_b << endl;//私有作用域下不可访问
}
int main0901(void) {
	//test0901();
	test0902();
	


	system("pause");
	return 0;
}