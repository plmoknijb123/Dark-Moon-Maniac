#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void manager::showinfo() {
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getdeptname()
		<< " \t��λְ������ϰ彻�������񣬲��·���Ա��" << endl;
}
string manager::getdeptname() {
	return string("����");
}