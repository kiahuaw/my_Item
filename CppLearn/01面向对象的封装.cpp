#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//面向对象学习   01   封装


//具有相同性质的对象  直接抽象为对象：人分为人类  车为车类。。。。。
/*
封装
将属性和行为作为一个整体表现生活中的事物

*/

//设计一个⚪类，求⚪的周长
//圆求周长的公式   2 * pi * r
//半径是圆的一个属性

const double PI = 3.14;
//创建一个类 类后面紧跟类名
class circle {
	//访问权限
//公共权限
public:
	//属性:（通常用变量）
	int m_r;//半径
	//行为:（行为通常用函数）
	//获取圆的周长
	double calculateZC() {
		return 2 * PI * m_r;
	}


};
int main0101(void) {
	//通过 类 来创建具体的  对象  的过程   ---实例化
	circle C1;
	C1.m_r = 10;
	cout << "圆的周长为：" << C1.calculateZC() << endl;



	system("pause");
	return 0;
}
//
//学生类
class student {// 属性和行为都叫做成员
public:
	//类中的属性和行为都叫做成员

	//属性  成员属性  成员变量
	string Name;//姓名
	int ID;//学号

	//行为  成员函数  成员方法
	//显示姓名和学号
	void showStudent() {
		cout << "姓名:" << Name << "\n学号:" << ID << endl;
		cout << "\n" << endl;
	}

	//给i姓名赋值
	void setName(string name) {
		Name = name;
	}

	//给学号赋值
	void setID(int id) {
		ID = id;
	}
};
int main0102(void) {
	// 创建一个具体的学生
	student stu1;
	//stu1.Name = "老鸭鸭";
	stu1.setName("老鸭鸭");
	//stu1.ID = 38250;
	stu1.setID(38250);
	//显示学生的信息
	stu1.showStudent();
	

	student stu2;
	stu2.Name = "Anna";
	stu2.ID = 12345;
	
	stu2.showStudent();
	


	system("pause");
	return 0;
}

//访问权限

//三种
//公共 publiic		成员类内可以访问      类外也可以访问
//保护 protected		成员类内可以访问	    类外不可以访问  子类也可以访问父类中 的保护内容
//私有 private		成员类内可以访问	    类外不可以访问  子类不可以访问父类中 的保护内容
class person {
public:
	//公共权限
	string Name;//姓名 
protected:
	//保护权限
	string Car;// 汽车

private:
	//私有权限
	int password;//银行卡密码
public:
	void func() {
		Name = "老鸭鸭";
		Car = "拖拉机";
		password = 123456;
	}
};


int main0103(void) {
	person p1;//实例化对象
	p1.Name = "SB";
	//p1.Car = ""//保护权限的内容  类外访问不到
	//p1.password = 123//私有权限的内容类外一样访问不到的


	system("pause");
	return 0;
}
//struct 和 class的默认访问权限不同前者是共有后者是私有



//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据的有效性

// 设计人的一个类 
class Person {
public:
	//设置姓名
	void setName(string name) {//对外提供一个公共的成员函数来对属性进行赋值
		Name = name;
	}
	//获取姓名
	string getName() {//对外的接口
		return Name;
	}
	int getAge() {//对外的一个接口
		return age;
	}
	void setAge(int Age) {
		if (Age > 0 && Age <= 150) age = Age;
		else {
			age = 0;
			cout << "年龄输入不合法" << endl;
			return;
		}
	}
	void setLover(string lover) {
		Lover = lover;
	}
	void showAll() {
		cout << "姓名: " << Name << "\n" << "年龄: " << age << "\n" << "对象不可查看\n" << endl;
	}
private:
	//姓名  可读可写
	string Name;
	//年龄  可读可写， 写的范围1-150
	int age;
	//对象  只写
	string Lover;
};
int main0104(void) {
	/*
	设置为私有 可以自己控制读写权限
	对于写权限 可以检测数据的有效性
	*/
	Person p;//的对象都不可以访问
	p.setName("老鸭鸭");
	p.setLover("年轻鸭鸭");
	p.setAge(138);
	p.showAll();


	system("pause");
	return 0;
}






















