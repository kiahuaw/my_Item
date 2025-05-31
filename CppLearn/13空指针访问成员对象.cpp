#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
c++中的空指针也是可以调用成员函数的
但是也要注意有没有用到的this指针

如果用到this 需要加以判断保证代码的健壮性
*/


class person {

public:

	void ShowClassName() {
		cout << "this person class " << endl;
	}


	void ShowPersonAge() {
		//报错原因时因为传入的指针时空null
		if (this == NULL)return;
		cout << "age = " << this->m_age << endl;
	}

	int m_age;
};

void test1301() {
	person* p = NULL;
	//p->ShowClassName();
	p->ShowPersonAge();// error
	return;
}
int main1301(void) {
	test1301();



	return 0;
}