#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
*分开存储
在c++中  类内的成员变量和成员函数分开存储
		只有非静态成员变量才属于类的对象上



*/
class person {


	int m_a;//只有非静态成员变量 属于类的对象上
	static int m_b;//静态成员变量 不属于类的对象上
	void func(){}// 非静态成员函数 不属于类的对象上
	static void func2(){}//静态成员函数 也不属于类的对象上
};
int person::m_b = 0;
void test1101() {
	person p;
	//空对象占用的内存空间为 1个字节大小
	//c++编译器会给每个空对象也分配一个字节空间
	//是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址

	cout << sizeof(p) << endl;


}
void test1102() {
	person p;//4个字节int
	cout << sizeof(p) << endl;

}
int main1101(void) {
	//test1101();
	test1102();
	return 0;
}