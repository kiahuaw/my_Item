#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
//#include <typeinfo>
using namespace std;

/*
2.因为Building的定义中需要
将Goodgay类的成员函数声明成友元成员函数，
所以Building类必须Goodgay类之后定义；
*/
class Building;
class goodGay17 {
public:

	goodGay17();

	void visit1();

	void visit2();

	Building* building;

};
class Building {
	//告诉编译器goodgay类下的visit成员函数作为本类的友元
	//可以访问私有成员
	friend void goodGay17::visit2();
public:
	Building();
public:

	string m_sittingoom;
private:

	string m_bedroom;
};
//类外实现成员函数
Building::Building() {
	m_sittingoom = "keting";
	m_bedroom = "woshi";
}
goodGay17::goodGay17() {
	building = new Building;

}
void goodGay17::visit1() {
	cout << "1 into " << building->m_sittingoom << endl;

}

void goodGay17::visit2() {
	cout << "2 into " << building->m_sittingoom << endl;
	cout << "2 into " << building->m_bedroom << endl;

}

void test1701() {
	goodGay17 gg;
	gg.visit1();
	gg.visit2();
}

int main1701(void) {
	test1701();




	return 0;
}