#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>

using namespace std;
/*
多态分为两类
	1、静态多态：函数重载和运算符重载属于静态多态 复用函数名
	2、动态多态：派生类和虚函数实现运行时多态
静态多态和动态多套区别：
	1、静态多态的函数地址早绑定-编译阶段确定地址
	2、动态多态的函数地址晚绑定-运行阶段确定地址
*/
//动态多态满足条件
//1、有继承关系
//2、子类要重写父类的虚函数
//重写->   函数返回值类型  函数名 参数列表 完全相同

//多态使用
//父类指针或引用指向子类对象

class Animal32 {
	//空类的大小是1
	//现在占8个字节  是指针 
public:
	virtual void speak() {// 虚函数
		cout << "动物在说话" << endl;
	}
};
//cat
class Cat :public Animal32 {

public:
	void speak() {
		cout << "猫在叫" << endl;
	}
};
//dog
class Dog :public Animal32 {
public:
	void speak() {
		cout << "狗在叫" << endl;
	}

};
//地址早绑定 在编译阶段就确定了函数地址
//如果想执行让猫说话 就使函数 地址晚绑定
void dospeak(Animal32 &animal) {
	animal.speak();
}


void test3201() {
	Cat cat;
	dospeak(cat);
	Dog dog;
	dospeak(dog);
}

void test3202() {
	cout << sizeof(Animal32) << endl;
	//
	/*
	vfptr   虚函数(表)指针
	vfptr -> vftable(存放的是虚函数表){
			表内部记录虚函数的地址
			&Animal::speak
	}
	v-virtual
	f-function
	ptr-pointer

	当子类重写父类的虚函数
		子类中的 虚函数表 会被替换成 子类的虚函数地址

	当父类指针或者指向子类对象的时候 就发生多态 


	*/
}
int main3201(void) {
	//test3201();
	test3202();


	return 0;
}
