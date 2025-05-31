#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
同普通和多态写两个进行运算的计算器类
多态优点 1代码组织结构清晰 2可读性强 3利于扩展维护

c++开发提倡利用多态设计程序架构 因为优点多
*/
using namespace std;
class Calculator33 {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		}
		else if (oper == "*") {
			return m_num1 * m_num2;
		}
		//如果想扩展新的功能 需要修改源码
		//在开发中 提倡开闭原则
		//对扩展进行开放 对修改进行关闭
	}
	int m_num1;//1
	int m_num2;//2
};

void test3301() {
	//创建计算器
	Calculator33 c;
	c.m_num1 = 132;
	c.m_num2 = 465;
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
}

//利用多态
// 实现计算器的基类
class AbstractCalculator {
public:
	virtual int getResult(){
		return 0;
	}
	int m_num1;
	int m_num2;
};

//设计加法计算器类
class AddCalulator : public AbstractCalculator {
	int getResult() {
		return m_num1 + m_num2;
	}
};

//剑法计算器类
class SubCalulator : public AbstractCalculator {
	int getResult() {
		return m_num1 - m_num2;
	}
};

//×s法计算器类
class MulCalulator : public AbstractCalculator {
	int getResult() {
		return m_num1 * m_num2;
	}
};

void test3302() {
	//多态使用的时候要父类指针或引用指向子类对象
	//+
	AbstractCalculator* abc = new AddCalulator;//父类指针指向new的子类对象
	abc->m_num1 = 1798;
	abc->m_num2 = 8466;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;

	//-
	abc = new SubCalulator;
	abc->m_num1 = 79846; 
	abc->m_num2 = 23155;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;

	abc = new MulCalulator;
	abc->m_num1 = 46515;
	abc->m_num2 = 31564;
	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
}

int main3301(void) {
	test3302
	();


	return 0;
}
