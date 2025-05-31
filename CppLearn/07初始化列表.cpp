#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//初始化列表


class person06 {
public:
	//传统初始化操作
	/*person06(int a, int b, int c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}*/

	//初始化列表初始化属性
	person06(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {



	}

	int m_a;
	int m_b;
	int m_c;


};


void test0601(){
	person06 p(3, 2, 1);
	cout << p.m_a << endl;
	cout << p.m_b << endl;
	cout << p.m_c << endl;
}

int main0701(void) {
	test0601();




	system("pause");
	return 0;
}