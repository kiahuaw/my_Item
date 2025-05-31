#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#define pi 3.14159265
using namespace std;

//创建立方体的类

	//行为
	//获取立方体表面积

	//设置&&获取长宽高

	//获取立方体体积

	//属性设置为私有
	//属性  长宽高

	//分别用全局函数和成员函数  判断两个立方体是否相等

class Cube {
public:
	void setLong(int long_) {
		Long = long_;
	}
	int getLong() {
		return Long;
	}
	void setWide(int wide) {
		Wide = wide;
	}
	int getWide() {
		return Wide;
	}
	void setHigh(int high) {
		High = high;
	}
	int getHigh() {
		return High;
	}
	int getVolume() {
		return Long * Wide * High;
	}
	int getArea() {
		return 2 * Long * Wide + 2 * Long * High + 2 * Wide * High;
	}

	//用成员函数判断两个立方体是否相等
	bool isSame(Cube C) {
		if (C.getHigh() == High && C.getLong() == Long && C.getWide() == Wide) {
			return true;
		}
		else return false;
	}
	//成员函数判断两个立方体面积是否相等
	bool isAreaSame(Cube C) {
		if (C.getArea() == 2 * Long * Wide + 2 * Long * High + 2 * Wide * High) {
			return true;
		}
		else return false;
	}
	//成员函数判断两个立方体体积是否相等
	bool isVolumeSame(Cube C) {
		if (C.getVolume() == Long * Wide * High) {
			return true;
		}
		else return false;
	}

private:
	//长宽高
	int Long;
	int Wide;
	int High;

};
bool SameOrNot(Cube &c1, Cube &c2) {//使用地址传递才能更好更简便地判断
	if (c1.getWide() == c2.getWide() && c1.getHigh() == c2.getHigh() && c1.getLong() == c2.getLong()) {
		return true;
	}
	else return false;
}


int main0201(void) {
	Cube C1;
	C1.setHigh(10);
	C1.setLong(20);
	C1.setWide(30);
	Cube C2;
	C2.setHigh(10);
	C2.setLong(30);
	C2.setWide(20);

	cout << "C1 的表面积为:" << C1.getArea() << endl;
	cout << "C1 的体积为  :" << C1.getVolume() << endl;
	cout << endl;
	cout << "C1 的表面积为:" << C2.getArea() << endl;
	cout << "C1 的体积为  :" << C2.getVolume() << endl;
	cout << endl;

	/*
	if (SameOrNot(C1, C2)) {
		cout << "C1和C2 是相等的" << endl;	
	}
	else {
		cout << "C1和C2 是不相等的" << endl;
	}*/
	if (C1.isSame(C2)) cout << "两个立方体完全相等" << endl;
	else cout << "两个立方体不完全相等" << endl;
	cout << endl;
	if (C1.isAreaSame(C2)) cout << "两个立方体的表面积相等" << endl;
	else cout << "两个立方体的表面积不相等" << endl;
	cout << endl;
	if (C1.isVolumeSame(C2)) cout << "两个立方体的体积相等" << endl;
	else cout << "两个立方体的体积不相等" << endl;


	system("pause");
	return 0;
}
//______________________________________________________________________________
//设计点和圆类计算点和圆的关系:  有点在圆外，在圆内 在圆上 在圆心s
//圆的行为和属性以及成员函数作为接口

class Circle {
	
public:

	double get_C_Area() {
		return 2 * pi * R * R;
	}
	//设置圆的半径
	void set_R(double r) {
		R = r;
	}
	//设置圆心坐标
	void set_Center(double x, double y) {
		X = x;
		Y = y;
	}
	void showData() {
		cout << "圆的半径R = " << R << endl;
		//cout << "圆心坐标(" << X << "," << Y << ")" << endl;
		printf("圆心坐标(%.2lf, %.2lf)\n", X, Y);
	}
	void PointLocation(double x, double y) {
		//pow(R, 2) - (pow(x - X, 2) + pow(y - Y, 2))
		if (X == x && Y == y) {
			printf("点(%.2f, %.2f)是圆心", x, y);
		}
		else if (pow(R, 2) - (pow(x - X, 2) + pow(y - Y, 2)) > 0.5) {
			printf("点(%.2f, %.2f)在圆内", x, y);
		}
		else if (pow(R, 2) - (pow(x - X, 2) + pow(y - Y, 2)) <= 0.5 
			&& pow(R, 2) - (pow(x - X, 2) + pow(y - Y, 2)) >= -0.5) {
			printf("点(%.2f, %.2f)在圆上", x, y);
		}
		else if (pow(R, 2) - (pow(x - X, 2) + pow(y - Y, 2)) < -0.5) {
			printf("点(%.2f, %.2f)在圆外", x, y);
		}
		
	}

private:
	double R;//	半径
	double X;// x坐标
	double Y;// y坐标
};



int main0202(void) {
	Circle C1;
	C1.set_Center(0, 0);
	C1.set_R(1);
	C1.PointLocation(sqrt(2), sqrt(2));
	//  可以在类中让另一个类作为本类中的成员 


	system("pause");
	return 0;
}

