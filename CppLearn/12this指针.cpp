#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//this指针  指向被调用成员函数所属对象
/*
C++通过提供特殊的对象指针解决 一块代码区分是哪个对象调用自己的
	this指针指向被调用成员函数所属的对象

this指针是隐含每一个非静态成员函数内的一种指针
this指针不用定义 可以直接使用

this指针的用途：
	当形参和成员变量同命时 可用this指针来区分
	在类的非静态成员函数中返回对象本身 可使用return *this
*/
/*
	1、解决名称冲突

	2、返回对象本身用*this
*/

class person {

public:
	person(int age) {//谁调用这个有参构造 this就指向谁
		//this指针指向  被调用的成员函数所属的对象
		this -> age =  age;//this -> p1	
	}

	//想调用本体就得用引用的方式进行返回
	//person& personaddage(person &p) {
	//用值的方式进行返回会调用拷贝构造函数创建一个新的对象

	person& personaddage(person &p) {
		this->age += p.age;
		//this 指向p2的指针
		return *this;
	}


	int age;
	


};

void test1201() {

	person p1(18);
	cout << p1.age << endl;
}
void test1202() {
	person p1(10);

	person p2(10);
	
	//链式编程思想
	p2.personaddage(p1).personaddage(p1).personaddage(p1).personaddage(p1);
	cout << p2.age << endl;
}
int main1201(void) {
	//test1201();
	test1202();


	return 0;
}