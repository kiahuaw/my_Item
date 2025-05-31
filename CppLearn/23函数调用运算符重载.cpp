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

/*()()()()()()()()
函数调用运算符（）也可以重载
由于重载后使用方式非常像函数的调用
	因此称为仿函数
仿函数没有固定写法 非常灵活
*/

class myprint {
public:
	void operator()(string test) {
		cout << test << endl;
	}
};

class myadd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};
void test2301() {
	myprint print;
	print("helloworld");
}
//仿函数非常的灵活//没有固定的写法
void test2302() {
	myadd myad;
	int temp = myad(100, 312);
	cout << temp << endl;

	//匿名函数对象  ->   当前行执行完了立即被释放
	cout << myadd()(123, 123) << endl;
}
void myprint02(string test) {
	cout << test << endl;
}
int main2301(void) {
	//test2301();
	//myprint02("helloworld");
	test2302();

	return 0;
}
