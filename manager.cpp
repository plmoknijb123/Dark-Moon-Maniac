#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void manager::showinfo() {
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getdeptname()
		<< " \t岗位职责：完成老板交给的任务，并下发给员工" << endl;
}
string manager::getdeptname() {
	return string("经理");
}