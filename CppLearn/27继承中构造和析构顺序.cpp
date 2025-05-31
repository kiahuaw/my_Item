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
子类继承父类后  当创建子类对象  也会调用父类的构造函数

	主要探究的是父类和子类的构造和析构顺序是哪个先哪个后


total : 继承中先调用父类构造函数 再调用子类构造函数
析构顺序与构造相反
*/

class base27 {

public:
	base27() {
		cout << "base构造函数" << endl;
	}
	~base27() {
		cout << "base析构函数" << endl;
	}


};

class son27 :public base27 {
public:
	son27() {
		cout << "son构造函数" << endl;
	}
	~son27() {
		cout << "son析构函数" << endl;
	}

};
void test2701() {
	//base b;
	son27 s;
	//继承中的构造和析构顺序如下
	//先构造父类 再构造子类  |  析构的顺序与构造的顺序相反

}

int main2701(void) {
	test2701();


	return 0;
}
