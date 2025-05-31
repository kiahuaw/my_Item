#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
	构造函数的调用规则
		如果用户自定义 有参 构造函数 c++不再提供默认无参构造
		但是会提供默认拷贝构造
		
		如果用户定义拷贝构造函数  c++不会再提供其他构造函数
*/
/*
深拷贝——浅拷贝

	浅拷贝——简单的赋值拷贝操作
		简单的等号赋值操作都叫浅拷贝
	深拷贝——在堆区申请空间进行拷贝操作


用编译器提供的拷贝构造函数会做浅拷贝操作


浅拷贝的问题要利用深拷贝的问题进行解决

***如果属性有在堆区进行开辟的 一定要自己提供拷贝构造函数
***防止浅拷贝带来的问题
*/
class person {

public:
	person() {
		cout << "person的构造函数调用" << endl;
	}

	person(int age, int height) {
		m_age = age;
		m_height = new int(height);
		cout << "person的有参构造函数调用" << endl;
	}
	//自己实现深拷贝构造函数来解决拷贝带来的问题

	person(const person& p) {

		cout << "person拷贝构造函数的调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;编译器默认实现的代码
		//深拷贝

		m_height = new int(*p.m_height);//重新申请一块空间使其指向这块内存



	}
	~person() {
		//析构代码将堆区开辟的数据做释放的操作
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "person的析构函数调用" << endl;
	}
	int m_age = 0;
	int* m_height;
};

void test_1() {
	person p1(18, 160);
	cout << "p1's age is :" << p1.m_age << endl;
	cout << "p1's height is :" << *p1.m_height << endl;

	person p2(p1);//浅拷贝 次会造成堆区内存重复释放  ---- 就是浅拷贝的问题
	cout << "p2's age is :" << p2.m_age << endl;
	cout << "p2's height is :" << *p2.m_height << endl;
}
int main0601(void) {
	test_1();




	system("pause");
	return 0;
}