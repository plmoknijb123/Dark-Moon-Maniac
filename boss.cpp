#include"boss.h"
boss::boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo() {
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getdeptname()
		<< " \t��λְ�𣺹���˾��������" << endl;
}
string boss::getdeptname() {
	return string("�ϰ�");
}