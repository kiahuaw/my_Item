#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
//#include <typeinfo>
using namespace std;
/*
常函数：
	成员函数后加const后我们称这个函数为常函数
	常函数内不可以修改成员属性
	成员属性声明时加关键字mutable后 在常函数中仍可以修改
常对象
	声明对象前加const称该对象为常对象
	常对象只能调用常函数

*/
class person {

public:
	//person * const this
	//this指针的本质 是指针常量 指针的指向是不可修改的
	void ShowPerson() const {//这里加的const本质上是上是给this 的const  让指针指向的值也不可以修改
		//m_a = 100;//ok + const not ok
		
		//this->m_a = 100;this指针不可以修改指针的指向的


	}
	void func(){}
	int m_a;
	mutable int m_b;//即使 在常函数中 也可以修改这个值  +关键字	
};
//常对象
void test1401() {
	const person p; //在对象前加const变为常对象
	//p.m_a = 1;   !
	p.m_b = 1;//ok是特殊的值 在常对象下可以修改

	//常对象只能调用常函数
	p.ShowPerson();
	//p.func();!

	return;
}
int main1401(void) {
	




	return 0;
}