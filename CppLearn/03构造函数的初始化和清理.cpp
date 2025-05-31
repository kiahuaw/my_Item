#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//对象的初始化和清理______________________
//构造函数--初始化
	/*
	类名(){}
	构造函数  没有返回值也不写void
	函数名称与类名相同
	构造函数可以有参数，所以可以发生重载
	程序在调用对象的时候会自动调用构造 无需手动调用 而且只会调用一次

	~类名(){}
	析构函数  没有返回值也不屑void
	函数名称与类名相同 在名称前面加上符号~
	析构函数不可以有参数  因此不能发生重载
	程序在对象销毁前会自动调用析构 无需手动调用 且只会调用一次
	*/
	//析构函数--清理
class Person01 {

public:
	//构造函数
	Person01() {
		cout << "person构造函数的调用" << endl;//如果不写东西就默认没有任何东西
	}

	//析构函数
	~Person01() {
		cout << "person析构函数的调用" << endl;
	}

};

//构造和析构都是必须有的实现，如果自己不提供 编译器会提供一个空实现的构造和析构
void test() {
	//Person01 p;//在栈区的数据  test01执行完毕就会释放这个对象，在释放对象前就会自动调用析构函数s
	
}

int main0301(void) {
	
	Person01 p;//在main函数中按任意键继续后还会出现析构函数的ma，只不过窗口被关闭了看不到


	system("pause");
	return 0;
}