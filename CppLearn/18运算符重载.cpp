#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
//#include <typeinfo>
using namespace std;

//运算符重载概念- 对已有的运算符重新进行定义 赋予其另一种功能
//以适应不同的数据类型 

//加号运算符重载
/*
1、成员函数重载加号

2、全局函数重载加号 
*/
/*
1、对于内置的数据类型的表达式的运算符是不可能改变的
	such as 1+1 != 0  and so on
2、不要滥用运算符重载!!!!!!
*/

class person18 {

public:
	//成员函数重载加号运算符
	
	person18 operator+(person18 &p) {
		person18 temp;
		temp.m_a = this->m_a + p.m_a;//this指向的是p
		temp.m_b = this->m_b + p.m_b;
		return temp;
	}
	int m_a;
	int m_b;

};
//01
//person18 operator+(person18 &p1, person18 &p2) {
//	person18 temp;
//	temp.m_a = p1.m_a + p2.m_a;
//	temp.m_b = p1.m_b + p2.m_b;
//	return temp;
//}

person18 operator+(person18& p1, int num) {
	person18 temp;
	temp.m_a = p1.m_a + num;
	temp.m_b = p1.m_b + num;
	return temp;
}

void test18() {
	person18 p1;
	p1.m_a = 10;
	p1.m_b = 20;
	cout << "p1.m_a = " << p1.m_a << endl;
	cout << "p1.m_b = " << p1.m_b << endl;
	cout << endl;

	person18 p2 = p1;
	p2.m_b = 10;
	p2.m_b = 20;
	cout << "p2.m_a = " << p2.m_a << endl;
	cout << "p2.m_b = " << p2.m_b << endl;
	cout << endl;

	// 成员函数重载的本质调用
	//person18 p3 = p1.operator+(p2);
	
	//全局函数重载的本质调用
	//person18 p3 = operator+(p1, p2);
	
	//运算符重载 也可以发生函数重载
	person18 p3 = p1 + p2;

	

	cout << "p3.m_a = " << p3.m_a << endl;
	cout << "p3.m_b = " << p3.m_b << endl;
	cout << endl;


	person18 p4 = p1 + 250;
	cout << "p4.m_a = " << p4.m_a << endl;
	cout << "p4.m_b = " << p4.m_b << endl;
	cout << endl;
	

}

int main1801(void) {
	
	test18();

	return 0;
}