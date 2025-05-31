#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*

*/
using namespace std;
class AbsDrink {
public:
	//煮水
	virtual void Boil() = 0;
	//冲炮
	virtual void Brew() = 0;
	//倒杯里
	virtual void PourCup() = 0;
	//加野
	virtual void AddSth() = 0;
	//制作饮品
	void MakeDrink() {
		Boil();
		Brew();
		PourCup();
		AddSth();
	}
};

class Coffee :public AbsDrink {
public:
	//煮水
	virtual void Boil() {
		cout << "正在烧制蒸馏水 -> ";
	}
	//冲炮
	virtual void Brew() {
		cout << "正在用科技冲泡咖啡 ->";
	}
	//倒杯里
	virtual void PourCup() {
		cout << "通过引流倒到碑中 ->";
	}
	//加野
	virtual void AddSth() {
		cout << "狠狠滴加科技\n";
	}
};
class Tea :public AbsDrink {
public:
	//煮水
	virtual void Boil() {
		cout << "正在烧制蒸馏水 -> ";
	}
	//冲炮
	virtual void Brew() {
		cout << "正在用科技冲泡茶 ->";
	}
	//倒杯里
	virtual void PourCup() {
		cout << "通过引流倒到碑中 ->";
	}
	//加野
	virtual void AddSth() {
		cout << "狠狠滴加科技 ->";
	}
};

void doWork(AbsDrink* abs) {
	abs->MakeDrink();
	delete abs;
}

void test3501() {
	//制作咖啡
	doWork(new Coffee);
	doWork(new Tea);
	
}

int main3501(void) {
	test3501();


	return 0;
}
