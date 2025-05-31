#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*
继承是面向对象三大特性之一
	有些类与类之间存在特殊的关系
	//我们发现定义这些类时下级别的成员除了拥有上一级的共性 还有自己的特性
	这时候我们就可以利用继承的技术减少重复代码

*/
using namespace std;
////java页面
//class java {
//public:
//	void header() {
//		cout << "首页 公开课 登录 注册 （公共头部） " << endl;
//	}
//	void footer() {
//		cout << "帮助中心 交流合作 站内地图 (公共底部) " << endl;
//	}
//	void left() {
//		cout << "java python c++ 。。。（公共分类列表）" << endl;
//	}
//	void content() {
//		cout << "java video" << endl;
//	}
//};

//用继承写的页面

//减少重复的代码 就是继承的好处  
/*
语法：  
class 子类：继承方式(01 父类  公共继承)

子类   也称为   派生类    
父类   也成为   基类->鸡肋
  */
class BasePage {
public:
	void header() {
			cout << "首页 公开课 登录 注册 （公共头部） " << endl;
	}
	void footer() {
		cout << "帮助中心 交流合作 站内地图 (公共底部) " << endl;
	}
	void left() {
		cout << "java python c++ 。。。（公共分类列表）" << endl;
	}
};
//java
class java :public BasePage {
public:
	void content() {
		cout << "java的学科视频" << endl;
	}
};
//py
class python :public BasePage {
public:
	void content() {
		cout << "python的学科视频" << endl;
	}
};
//c++
class cpp :public BasePage {
public:
	void content() {
		cout << "cpp的学科视频" << endl;
	}
};
void test2401() {
	cout << "java 的下载视频页面如下：" << endl;
	java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "_______________________" << endl;
	cout << "python 的下载视频页面如下：" << endl;
	python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "_______________________" << endl;
	cout << "java 的下载视频页面如下：" << endl;
	cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();
	cout << "_______________________" << endl;
	
}
int main2401(void) {
	test2401();


	return 0;
}
