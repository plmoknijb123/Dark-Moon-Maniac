#include<iostream>
#include"workerManager.h"
#include"worker.h"
using namespace std;
int main() {
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;//用来存储用户的选项
	while (true) {
		//调用展示菜单成员函数
		wm.show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;//接收用户选项
		switch (choice)
		{
		case 0: //退出系统
			wm.exitsystem();
			break;
		case 1: //添加职工
			wm.add_emp();
			break;
		case 2: //显示职工
			wm.show_emp();
			break;
		case 3: //删除职工
			wm.del_emp();
			break;
		case 4: //修改职工
			wm.mod_emp();
			break;
		case 5: //查找职工
			wm.find_emp();
			break;
		case 6: //排序职工
			wm.sort_emp();
			break;
		case 7: //清空文件
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