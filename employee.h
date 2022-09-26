#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//职工抽象类
class employee: public work{
public:
	//构造函数
	employee(int id,string name,int did);
	//显示个人信息
	virtual void showinfo() ;
	//显示岗位名称
	virtual string getdeptname();
};
