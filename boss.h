#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//老板抽象类
class boss : public work {
public:
	//构造函数
	boss(int id, string name, int did);
	//显示个人信息
	virtual void showinfo();
	//显示岗位名称
	virtual string getdeptname();
};
