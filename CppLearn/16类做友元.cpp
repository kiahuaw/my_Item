#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
//#include <typeinfo>
using namespace std;
//lei做友元
/*
class Building;

class goodGay {

public:
	goodGay();
	void Visit();//访问build所有的属性

	Building* building;
};

class Building {
	friend class goodGay;//goodgay是本类的友元  可以访问本类中的私有成员
public:
	Building();


public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};


Building::Building() {
	m_SittingRoom = "keting";
	m_BedRoom = "woshi";
}
goodGay::goodGay() {
	//创建一个建筑物的对象
	building = new Building;

}
void goodGay::Visit() {
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}
void test1601() {
	goodGay gg;
	gg.Visit();
}
int main1601(void) {

	test1601();



	return 0;
}*/