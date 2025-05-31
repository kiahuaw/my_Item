#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
/*
#include <algorithm>//算法类头文件
#include<list>//链表头文件
#include<map>//图
#include<queue>//队列
#include<iterator>//迭代器
#include<stack>//栈
#include <typeinfo>//类型头
*/
using namespace std;
//左移运算符配和友元可以实现输出自定义数据类型

/*
  左移运算符重载
可以输出自定义的数据类型
*/
class person19 {
	friend ostream& operator<<(ostream& cout, person19& p);
	
public:
	person19(int a, int b, int c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}

private:
	//利用成员函数重载  左移运算符p.operator<<(cout)
	//不会用成员函数重载<<左移运算符  因为无法实现cout在左侧
	/*void operator<<() {

	}*/

	int m_a;
	int m_b;
	int m_c;
};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &cout, person19 &p) {  //operator<<(cout, p)   简化cout << p
	cout << "m_a = " << p.m_a << "\nm_b = "
		<< p.m_b << "\nm_c = " << p.m_c << endl;
	return cout;
}

void test1901() {
	person19 p(10, 20, 30);
	
	//加endl换行
	cout << p <<  "helloworld" << endl;
}

int main1901(void) {
	test1901();



	return 0;
}
