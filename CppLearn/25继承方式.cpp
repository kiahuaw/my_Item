#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>

using namespace std;
/*
继承方式有三种
	1、公共继承public
	2、保护继承protected
	3、私有继承private
*/
class Base1 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
//公共继承
class son :public Base1 {
public:
	void func() {
		m_a = 10;//ok  父类中的公共权限成员 到子类中依然是公共权限

		m_b = 10;//ok  父类中的保护权限成员 到子类中依然是保护权限

		//m_c = 10;//!ok  父类中的私有权限成员 到子类中访问不到
	}
};
void test2501() {
	son s1;
	s1.m_a = 100;
	//s1.m_b = 100;//!ok  到son中m_b是保护权限 类外访问不到

}


//保护继承
class base2 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son2 :protected base2 {
public:
	void func() {
		m_a = 10; //ok父类中公共成员 到子类中变为保护权限
		m_b = 100;
		//m_c = 100;//!ok  子类永远访问不到父类中的私有成员

	}
};
void test2502() {
	son2 s;
	//s.m_a = 100;//!ok  son2中m_a变为保护权限 因此类外访问不到
	//s.m_b = 10;//!ok   son2中m_b保护权限 不可以访问
}
class base3 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class son3 :private base3 {
public:
	void func(){
		m_a = 100;//公共成员 到 子类中变为 私有的
		m_b = 100;//保护成员 到 子类中变为 私有的
		//m_c = 100;//父类中私有成员 子类访问不到
	}
};
void test2503() {
	son3 s;
	//s.m_a = 100;	!ok  到son3 变为私有的成员 类外访问不到
	//s.m_b = 12132;!ok到son3 变为私有的成员 类外访问不到

}
class grandson3 :public son3 {
public:
	void func(){
		//m_a = 100;  到了son3中m_a变为私有 即使是儿子也访问不到
		//m_b = 12312;   b  so as
	}
};
int main2501(void) {



	return 0;
}
