#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
#include <fstream>
#define  FILENAME "empFile.txt"
using namespace std;
class WorkerManager{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵���������
	void show_menu();

	//�˳�����
	void exitsystem();

	//��¼ְ������
	int m_empnum;

	//ְ������ָ��
	work **m_emparray;

	//���ְ������
	void add_emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_fileisempty;

	//ͳ���ļ�������
	int get_empnum();

	//��ʼ��Ա��
	void init_emp();

	//��ʾְ��
	void show_emp();
	
	//ɾ��ְ��
	void del_emp();
	
	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������λ�ã������ڷ���-1
	int isexist(int id);
	
	//�޸�ְ��
	void mod_emp();

	//����ְ��
	void find_emp();

	//����ְ����Ž�������
	void sort_emp();

	//����ļ�
	void clean_file();

	//��������
	~WorkerManager();
};