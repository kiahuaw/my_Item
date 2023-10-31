#pragma once
#include "data.h"
#include "Block.h"
class Map {
public:
	Map();//构造函数初始化
	void Loop(void);//主循环
	void Init();//与构造函数一样
	void InitFalling();//初始化下落矩阵吧？
	void DataToShow();//一维数组转化成二进制二维数组表示
	void FallingToFlag();//一样，
	void Falling1Times();//下落一次
	void LeftMove();//左移
	void RightMove();//右移
	void DownMove();//下移
	int StopFallingJudge();//停止下落的判断
	void FallingToData();//将下落方块输入data
	void Remove();//移除满行
	int RandBlock();//随机0-6的方块s
	void NextToShow(int n);//暴力列举方块
	void BlockToFalling(int n);//初始化方块到falling
	void Spin(void);//旋转函数
	void FlagToFalling();//旋转函数用到的
	void Control();//控制函数
	void Show(void);//简单的显示函数
	void ScoreSave(void);
	void RandomGenerator_Bag1();//随机数生成器，产生7个不同的随机数
	void RandomGenerator_Bag2();//随机数生成器，产生7个不同的随机数
	void Bag2ToBag1();
	void Shuffle(int obs[]);

	int Score;//分数
	int Best;
	int nowblocknum;//现在方块的数字
	int nextblocknum;//下一个方块的数字
	
	int bag7_1[7];//一组包随机生成器（Random Generator，“7-Bag”）
	int bag7_2[7];//二组包随机生成器（Random Generator，“7-Bag”）
	int nextblock[4][3];//下一个方块的二维数组
	int data[25]; //data25   //最后一层是1111111111方便判断停止
 	int falling[24]; //只含下落方块
	int flag[24][10]; //falling的对照
	int show[24][10];//24  10
	char mapchar[24][11];//24 11 //数字转二进制二维数组用到的

	Block b;//block初始化的类
	POINT s[20][10];//show的坐标
	POINT next[4][3];//下一个方块的坐标
	clock_t start, end, up, down;//记录时间用的
};

