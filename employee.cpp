#include"employee.h"

	//���캯��
	employee::employee(int id, string name, int did){
		this->m_Id = id;
		this->m_name = name;
		this->m_deptid = did;
		
	}
	//��ʾ������Ϣ
	void employee::showinfo(){
		cout << "ְ����ţ� " << this->m_Id
			<< " \tְ�������� " << this->m_name
			<< " \t��λ��" << this->getdeptname()
			<< " \t��λְ����ɾ�����������" << endl;
	}
	//��ʾ��λ����
	string employee::getdeptname() {
		return string("Ա��");
	}