#include<iostream>
#include"workerManager.h"
#include"worker.h"
using namespace std;
int main() {
	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;//�����洢�û���ѡ��
	while (true) {
		//����չʾ�˵���Ա����
		wm.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;//�����û�ѡ��
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitsystem();
			break;
		case 1: //���ְ��
			wm.add_emp();
			break;
		case 2: //��ʾְ��
			wm.show_emp();
			break;
		case 3: //ɾ��ְ��
			wm.del_emp();
			break;
		case 4: //�޸�ְ��
			wm.mod_emp();
			break;
		case 5: //����ְ��
			wm.find_emp();
			break;
		case 6: //����ְ��
			wm.sort_emp();
			break;
		case 7: //����ļ�
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}