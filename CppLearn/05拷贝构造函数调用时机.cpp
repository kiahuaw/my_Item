#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
C++中拷贝构造函数调用实际有三种情况
	使用一个已经创建完毕的对象来初始化一个新对象
	值传递的方式给函数的参数传值
	以值的方式返回局部对象
*/
class Person03 {
public:
	Person03(){
		cout << "person默认构造函数调用" << endl;
	}
	Person03(int age) {
		cout << "person有参构造函数调用" << endl;
		Age = age;
	}
	Person03(const Person03& p) {
		cout << "person拷贝构造函数调用" << endl;
		Age = p.Age;
	}
	~Person03(){
		cout << "person默认析构函数调用" << endl;
	}
	int Age;
};

void test02() {
	Person03 p1(20);
	Person03 p2(p1);

	return;
}

void dowork(Person03 p) {

}
void test03() {
	Person03 p;
	dowork(p);
	return;
}

Person03 doWork2() {
	//值方式返回局部对象
	Person03 p1;
	return p1;
}
void test04() {
	Person03 p = doWork2();
}
int main0501(void) {
	//test02();
	//test03();
	test04();



	return 0;
}