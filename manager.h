#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//���������
class manager : public work {
public:
	//���캯��
	manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ʾ��λ����
	virtual string getdeptname();
};