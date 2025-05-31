#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
当父类与子类出现同名的成员 如何通过子类对象 
	访问到子类或父类中同名的数据

	1、访问子类同名成员 直接访问
	2、访问父类同名成员 加作用域
*/

/*total
1、子类对象可以直接访问到子类中同名成员
2、子类对象加作用域可以访问到父类同名成员
3、当子类与父类拥有同名的成员函数 子类会隐藏父类中同名成员函数 
	加作用域可以访问到父类中同名成员函数
*/
using namespace std;

class base28 {
public:
	base28() {
		m_a = 100;
	}

	void func() {
		cout << "base - func() " << endl;
	}
	void func(int a) {
		cout << "base - func(int a) " << endl;
	}
	int m_a;

};

class son28 :public base28 {
public:
	son28() {
		m_a = 200;
	}
	void func() {
		cout << "son - func() " << endl;
	}
	int m_a;
};
//同名成员属性处理方式s
void test2801() {
	son28 s;
	cout << "son.m_a = " << s.m_a << endl;//直接输出是200
	//如果通过子类对象 访问到父类中同名成员 需要加作用域
	cout << "base.m_a = " << s.base28::m_a << endl;//
}
//同名成员函数处理方式
void test2802(){
	son28 s;
	s.func();//出现同名的直接访问子类
	s.base28::func();
	//如果子类中出现和父类同名成员函数 子类的同名成员会隐藏掉父类中所有的
	//同名成员函数s
	//访问父类中被隐藏的同名成员函数 要加作用域
	s.base28::func(100);
}
int main2801(void) {
	//test2801();
	test2802();


	return 0;
}
