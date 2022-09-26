#pragma once
#include<iostream>
#include<string>
using namespace std;
//职工抽象类
class work {
public:
	//显示个人信息
	virtual void showinfo() = 0;
	//显示岗位名称
	virtual string getdeptname() = 0;
	//成员属性
	//员工编号
	int m_Id;
	//员工姓名
	string m_name;
	//部门编号
	int m_deptid;
};