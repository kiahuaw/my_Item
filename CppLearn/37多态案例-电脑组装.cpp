#define _CRT_SECURE_NO_WARNINGS
#include <iostream>//标准输入输出流
#include <string>//字符串类头文件
#include <cmath>//数学类头文件
#include <ctime>
/*

*/
using namespace std;

class CPU {
public:
	virtual void Cal() = 0;
};

class VideoCard {
public:
	virtual void Display() = 0;
};

class Memory {
public:
	virtual void Storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作函数
	void Work() {
		m_cpu->Cal();
		m_vc->Display();
		m_mem->Storage();
	}
private:
	CPU* m_cpu;//cpu指针
	VideoCard* m_vc;//显卡指针
	Memory* m_mem;//内存指针
};
class intelCPU :public CPU {
public:
	virtual void Cal() {
		cout << "intelCPU is working" << endl;
	}
};

class intelVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "intelVideoVard is working" << endl;
	}
};

class intelMemory :public Memory {
public:
	virtual void Storage() {
		cout << "intelMemory is working" << endl;
	}
};
//lenovo
class lenovoCPU :public CPU {
public:
	virtual void Cal() {
		cout << "lenovoCPU is working" << endl;
	}
};

class lenovoVideoCard :public VideoCard {
public:
	virtual void dispaly() {
		cout << "lenovoVideoVard is working" << endl;
	}
};

class lenovoMemory :public Memory {
public:
	virtual void Storage() {
		cout << "lenovoMemory is working" << endl;
	}
};

void test3701() {
	//01


}

int main(void) {
	test3701();


	return 0;
}
