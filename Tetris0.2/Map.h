#pragma once
#include "data.h"
#include "Block.h"
class Map {
public:
	Map();//���캯����ʼ��
	void Loop(void);//��ѭ��
	void Init();//�빹�캯��һ��
	void InitFalling();//��ʼ���������ɣ�
	void DataToShow();//һά����ת���ɶ����ƶ�ά�����ʾ
	void FallingToFlag();//һ����
	void Falling1Times();//����һ��
	void LeftMove();//����
	void RightMove();//����
	void DownMove();//����
	int StopFallingJudge();//ֹͣ������ж�
	void FallingToData();//�����䷽������data
	void Remove();//�Ƴ�����
	int RandBlock();//���0-6�ķ���s
	void NextToShow(int n);//�����оٷ���
	void BlockToFalling(int n);//��ʼ�����鵽falling
	void Spin(void);//��ת����
	void FlagToFalling();//��ת�����õ���
	void Control();//���ƺ���
	void Show(void);//�򵥵���ʾ����
	void ScoreSave(void);
	void RandomGenerator_Bag1();//�����������������7����ͬ�������
	void RandomGenerator_Bag2();//�����������������7����ͬ�������
	void Bag2ToBag1();
	void Shuffle(int obs[]);

	int Score;//����
	int Best;
	int nowblocknum;//���ڷ��������
	int nextblocknum;//��һ�����������
	
	int bag7_1[7];//һ��������������Random Generator����7-Bag����
	int bag7_2[7];//����������������Random Generator����7-Bag����
	int nextblock[4][3];//��һ������Ķ�ά����
	int data[25]; //data25   //���һ����1111111111�����ж�ֹͣ
 	int falling[24]; //ֻ�����䷽��
	int flag[24][10]; //falling�Ķ���
	int show[24][10];//24  10
	char mapchar[24][11];//24 11 //����ת�����ƶ�ά�����õ���

	Block b;//block��ʼ������
	POINT s[20][10];//show������
	POINT next[4][3];//��һ�����������
	clock_t start, end, up, down;//��¼ʱ���õ�
};

