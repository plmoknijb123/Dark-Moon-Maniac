#pragma once
#include<iostream>
#include<string>
using namespace std;
//ְ��������
class work {
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;
	//��ʾ��λ����
	virtual string getdeptname() = 0;
	//��Ա����
	//Ա�����
	int m_Id;
	//Ա������
	string m_name;
	//���ű��
	int m_deptid;
};