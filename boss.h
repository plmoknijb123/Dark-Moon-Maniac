#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//�ϰ������
class boss : public work {
public:
	//���캯��
	boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ʾ��λ����
	virtual string getdeptname();
};
