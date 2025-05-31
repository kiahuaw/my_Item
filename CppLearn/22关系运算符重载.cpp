#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
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
/*
关系运算符重载
	作用：
		重载关系运算符==/>/< 可以让两个自定义类型对象
		进行对比操作 
*/

class person22 {
public:
	person22(int age, string name) {
		m_age = age;
		m_name = name;
	}
	//重载=====号
	bool operator==(person22 &p) {
		if (this->m_age == p.m_age && this->m_name == p.m_name)return 1;
		else return 0;
	}
	bool operator!=(person22& p) {
		if (this->m_age != p.m_age && this->m_name != p.m_name) return 1;
		else return 0;
	}
	bool operator>(person22& p) {
		if (this->m_age > p.m_age) return 1;
		else return 0;
	}
	bool operator<(person22& p) {
		if (this->m_age < p.m_age) return 1;
		else return 0;
	}


	int m_age;
	string m_name;
};

void test2201() {
	person22 p1(10, "ljj");
	person22 p2(10, "ljj");
	if (p1 == p2) 
		cout << "p1 == p2" << endl;
	else 
		cout << "p1 != p2" << endl;

	if (p1 != p2)
		cout << "p1 != p2" << endl;
	else
		cout << "p1 == p2" << endl;

	if (p1 > p2) cout << "p1.age > p2.age" << endl;
	else cout << "p1.age < p2.age" << endl;

	if (p1 < p2) cout << "p1.age < p2.age" << endl;
	else cout << "p1.age > p2.age" << endl;

}

int main2201(void) {
	test2201();


	return 0;
}
