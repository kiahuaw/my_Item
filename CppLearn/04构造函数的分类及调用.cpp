#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
构造函数的分类及调用
	两种分类方式：
		按参数分为：有参构造和无参构造
		按类型分为：普通构造和拷贝构造
	三种调用方式：
		括号法
		显示法
		隐式转换法

*/


//分类
//按照参数  无参和有参
//按照类型分类  普通和拷贝
class Person02 {
public:
	//构造函数
	Person02() {
		cout << "person的无参构造(默认构造)函数调用" << endl;
	}
	Person02(int a) {
		age = a;
		cout << "person的有参构造函数调用" << endl;
	}
	
	//拷贝构造函数
	Person02(const Person02 &p) {//不可修改而且要把原来的对象给传进来 
		//将传入的对象的所有的属性拷贝到本对象
		cout << "person的拷贝构造函数调用" << endl;
		age = p.age;
	}
	~Person02() {
		cout << "person的析构函数调用" << endl;
	}
	int age;
};

//调用
void test01() {
	//括号法---常用
	//Person02 p1;//默认构造函数
	//Person02 p2(10);//会调用有参构造函数
	//Person02 p3(p2);//拷贝构造函数
	//cout << "p1's age : " << p1.age << endl;
	//cout << "p2's age : " << p2.age << endl;
	//cout << "p3's age : " << p3.age << endl;
	
	//注意事项
	//在调用默认构造函数的时候不要加小括号, 就是不要传参
	//直接没创建出来对象
	
	//Person02 p1();//因为编译器会认为是一个p1()函数的声明  不会认为在创建对象

	//显示法
	Person02 p4;
	Person02 p5 = Person02(10);//有参构造

	//显示fa调用拷贝构造
	Person02 p6 = Person02(p5);

	//Person02(10);//单独拿出来叫做  匿名对象  系统会立即回收掉匿名对象
	//cout << "666" << endl;
	
	//注意事项2
	// 不要利用拷贝构造函数来初始化匿名对象
	//Person02(p6);//编译器认为代码在定义一个person02 p6的意思

	//隐式转换法
	Person02 p7 = 10; //相当于写了 person p7 = person(10)相当于有参构造
	Person02 p8 = p4;
}

int main0401(void) {
	test01();



	return 0;
}