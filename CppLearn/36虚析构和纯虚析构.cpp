#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
多态使用时 如果子类中有属性开辟到堆区 则父类指针在释放时无法调用到子类的析构代码

解决：将父类中的析构函数改为虚析构 或者纯虚析构

虚析构和纯虚析构共性
	1、可以解决父类指针释放子类对象
	2、都需要有具体的函数实现
虚析构和纯虚析构区别
	如果时纯虚析构 该类属于抽象类 无法实例化对象



总：==
	1、虚析构或纯虚析构就是用来通过解决父类指针释放子类对象
	2、如果子类中没有堆区数据 可以不写为虚构或纯虚析构
	3、拥有纯虚析构函数的类也属于抽象类
*/
using namespace std;

class Animal36 {
public:
	Animal36() {
		cout << "animal构造函数" << endl;
	}
	virtual void speak() = 0;
	//利用虚析构解决 父类指针释放子类对象不干净的问题
	/*virtual ~Animal36() {
		cout << "animal析构函数" << endl;
	}*/
	//纯虚析构  报错
	virtual ~Animal36() = 0;
};
Animal36::~Animal36(){//需要有声明 也需要实现
	cout << "animal纯虚析构函数" << endl;
}
class cat36 :public Animal36 {
public:
	cat36(string name) {
		cout << "cat构造函数" << endl;
		m_name =  new string(name);
	}
	virtual void speak() {
		cout << *m_name <<" -> cat is speaking" << endl;
	}
	~cat36() {
		if (m_name != NULL) {
			cout << "cat析构函数" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	string* m_name;//堆区数据
};


void test3601() {
	Animal36* animal = new cat36("tom");
	animal->speak();	
	//父类指针在析构时候不会调用子类中的析构函数 导致子类如果有堆区属性 出现内存泄露
	delete animal;



}
int main(void) {
	test3601();


	return 0;
}
