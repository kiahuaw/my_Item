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

//通过重载递增运算符实现自己的整形数据

// 自定义整形

//前置递增返回引用  后置递增返回值

class myint {
	friend ostream& operator<<(ostream& cout, myint i);
public:
	myint() {
		m_num = 0;
	}

	//重载++运算符

	//++分为两种：前置和后置
	//front
	//返回引用是为了一直对一个数据进行递增操作
	myint& operator++() {//返回引用才正确 
		//返回的是值的话就不是在对传进来的
		//同一个数据进行操作了
		m_num++;
		return *this;
		//把自身做一个返回下面的cout才能输出
	}
	//behind
	//void operator++(int)  int代表占位参数  可以用于区分前置和后置递增
	myint operator++(int) {//只认递增
		//不返回引用了，要不然返回的就是局部对象的引用  执行完会被销毁

			//first 记录当时的结果
		myint temp = *this;//自身

		//next 递增
		m_num++;

		//final 最后的结果返回
		return temp;

	}
	myint& operator--() {
		m_num--;
		return *this;
	}
	myint operator--(int) {
		myint temp = *this;
		m_num--;
		return temp;
	}


private:
	int m_num;
};

//chongzai <<
ostream& operator<<(ostream& cout, myint i) {
	cout << i.m_num << endl;
	return cout;
}

void test2001() {
	myint i;
	//重载左移运算符要写在全局函数 
	cout << ++(++i) << endl;
	cout << i << endl;

}

void test2002() {
	myint j;
	cout << j++ << endl;
	cout << j << endl;
}

void test2003() {
	myint k;
	cout << --k << endl;
	cout << k << endl;
}

void test2004() {
	myint u;
	cout << u-- << endl;
	cout << u << endl;
}

int main2001(void) {
	//test2001();
	//test2002();
	//test2003();
	test2004();
	

	return 0;
}
