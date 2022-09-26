#pragma once//防止头文件重复包含
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
	//构造函数
	WorkerManager();

	//展示菜单函数声明
	void show_menu();

	//退出函数
	void exitsystem();

	//记录职工人数
	int m_empnum;

	//职工数组指针
	work **m_emparray;

	//添加职工功能
	void add_emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_fileisempty;

	//统计文件中人数
	int get_empnum();

	//初始化员工
	void init_emp();

	//显示职工
	void show_emp();
	
	//删除职工
	void del_emp();
	
	//判断职工是否存在，如果存在返回职工所在数组的位置，不存在返回-1
	int isexist(int id);
	
	//修改职工
	void mod_emp();

	//查找职工
	void find_emp();

	//按照职工编号进行排序
	void sort_emp();

	//清空文件
	void clean_file();

	//析构函数
	~WorkerManager();
};