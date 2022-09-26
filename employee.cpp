#include"employee.h"

	//构造函数
	employee::employee(int id, string name, int did){
		this->m_Id = id;
		this->m_name = name;
		this->m_deptid = did;
		
	}
	//显示个人信息
	void employee::showinfo(){
		cout << "职工编号： " << this->m_Id
			<< " \t职工姓名： " << this->m_name
			<< " \t岗位：" << this->getdeptname()
			<< " \t岗位职责：完成经理交给的任务" << endl;
	}
	//显示岗位名称
	string employee::getdeptname() {
		return string("员工");
	}