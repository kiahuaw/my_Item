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

/*
c++编译器至少给一个类添加4个函数
	1、默认构造函数（无参 函数体为空）
	2、默认析构函数（无参 函数体为空）
	3、默认拷贝构造函数 对属性进行值拷贝
	4、赋值运算符operator= 对属性进行值拷贝

	如果类中有属性指向堆区 做赋值操作时也会出现深浅拷贝问题

*/

class person21 {
public:
	person21(int age) {
		m_age = new int(age);

	}
	~person21() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}
	//返回引用才是它真正的自身
	person21& operator=(person21 &p) {
		//编译器是提供浅拷贝
		//m_age = p.m_age


		//应该先判断是否有属性在堆区 如果有就先释放  再深拷贝
		if(m_age != NULL){
			delete m_age;
			m_age = NULL;
		}
		// 深拷贝
		m_age = new int(*p.m_age);
		return *this;
	}
	int* m_age;
};

void test2101() {
	person21 p1(18);
	person21 p2(38);
	person21 p3(58);
	p3 = p2 = p1;
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;
	cout << *p3.m_age << endl;



}

int main2101(void) {
	
	test2101();

	return 0;
}
