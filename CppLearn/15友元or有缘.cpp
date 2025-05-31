#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
//#include <typeinfo>
using namespace std;
//

/*
有缘的关键字是friend 
	有缘的三种实现
		全局函数做友元
		类做友元
		成员函数做友元
友元的目的就是让一个函数或者类 访问另一个类中的私有成员
*/
//建筑物的一个类
/*
class Building {
	
	friend void goodGay(Building* building);
	//这个函数是building的友元 可以访问本类的私有成员甚至不用public
public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";

	}
	string m_SittingRoom;
private:
	string m_BedRoom;


};*/
/*
void goodGay(Building *building) {

	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;

}
*/
/*
/*
void test1501() {
	Building Bu;
	goodGay(&Bu);
	 
}

int main1501(void) {
	test1501();


	return 0;
}*/