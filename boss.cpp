#include"boss.h"
boss::boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo() {
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getdeptname()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
string boss::getdeptname() {
	return string("老板");
}