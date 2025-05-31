#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
#include <algorithm>//算法类头文件
#include<list>//链表头文件
#include<map>//图
#include<queue>//队列
#include<iterator>//迭代器
#include<stack>//栈
#include <typeinfo>//类型头
*/
using namespace std;
//继承中的对象模型
class base {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class son :public base {

public:
	int m_d;
};


void test2601() {
	//16   在父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器给隐藏了 因此是访问不到 但是确实被继承了
	cout << "sizeof(son) = " << sizeof(son) << endl;

}
//开发人员的提示工具可以查看对象模型
//
int main2601(void) {
	
	test2601();

	return 0;
}
