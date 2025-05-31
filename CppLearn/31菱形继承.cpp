#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
using namespace std;
/*
菱形继承概念:
	两个派生类继承同一个基类
	又有1个类同时继承着两个派生类
//问题

*/
class Animal {
public:
	int m_age;
};
//利用虚继承解决菱形继承的问题 
// 继承之前 加上关键字 virtual 变为虚继承
// animal称为虚基类
//vbptr虚基类指针指向vbtable指向一个虚基类表  	v-virtual   b-base    ptr-pointer
//virtual
//羊类
class Sheep:virtual public Animal {

};
//驼类s
class Tuo :virtual public Animal {

};
//羊驼类
class SheepTuo :public Sheep, public Tuo {
	
};
void test3101() {
	SheepTuo st;

	st.Sheep::m_age = 28;
	st.Tuo::m_age = 18;
	//出现菱形继承 两个父类拥有相同的数据 需要加以作用域区分
	cout << "st.Sheep::m_age =" << st.Sheep::m_age << endl;
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;
	cout << "st.m_age = " << st.m_age << endl;
	//数据只需要一份 现在导致浪费资源



}
int main3101(void) {
	test3101();


	return 0;
}
