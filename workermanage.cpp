#include"workerManager.h"
WorkerManager::WorkerManager() {
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open()) {
		//cout << "文件不存在"<<endl;
		//初始化属性
		//初始化记录人数
		this->m_empnum = 0;
		//初始化数组指针
		this->m_emparray = NULL;
		//初始化文件是否为空
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		//cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_empnum = 0;
		//初始化数组指针
		this->m_emparray = NULL;
		//初始化文件是否为空
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//3.文件存在，并且记录数据
	int num = this->get_empnum();
	//cout << "职工的人数为：" << num << endl;
	this->m_empnum = num;
	//开辟空间
	this->m_emparray = new work * [this->m_empnum];
	//将文件中的数据存到数组中
	this->init_emp();
	
}
//展示菜单
void WorkerManager::show_menu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitsystem() {
	cout << "欢迎下次在使用" << endl;
	system("pause");
	exit(0);//退出程序
}
//添加员工
void WorkerManager::add_emp() {
	cout << "请输入添加员工的数量：" << endl;
	int addnum = 0;//保存用户输入的数量
	cin >> addnum;
	if (addnum > 0) {
		//添加
		//计算添加新空间大小
		//新空间大小=原来记录人数+新增人数
		int newsize = this->m_empnum + addnum;
		//开辟新空间
		work **newspace=new work*[newsize];
		//将原来空间的数据拷贝到新空间下
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] =this-> m_emparray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addnum; i++) {
			int id;//职工编号
			string name;//职工姓名
			int dselect;//部门选择
			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;
			work * work = NULL;
			switch (dselect)
			{
			case 1:
				work = new employee(id, name, 1);
				break;
			case 2:
				work = new manager(id, name, 2);
				break;
			case 3:
				work = new boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针保存到数组中
			newspace[this->m_empnum + i] = work;
		}
		//释放原有空间
		delete[] this->m_emparray;
		//更改新空间的指向
		this->m_emparray = newspace;
		//更新新的职工人数
		this->m_empnum = newsize;
		//更新职工不为空的标志
		this->m_fileisempty = false;
		//提示添加成功
		cout << "成功添加" << addnum << "名员工" << endl;
		//保存文件
		this->save();
		
		
	}
	else{
		cout << "输入有误" << endl;
	}
	//按任意键后清屏返回上级目录
	system("pause");
	system("cls");
}
//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出方式打开文件，相当于写文件
	//将每个人的数据写入文件中
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparray[i]->m_Id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::get_empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件，读文件
	int id;
	string name;
	int did;
	int num = 0;
	if (ifs >> id && ifs >> name && ifs >> did) {
		//统计人数变量
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件，读文件
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		work* work = NULL;
		//根据不同的部门Id创建不同对象
		if (did == 1)  // 1普通员工
		{
			work = new employee(id, name, did);
		}
		else if (did == 2)  // 2经理
		{
			work = new manager(id, name, did);
		}
		else if (did == 3)  // 3boss
		{
			work = new boss(id, name, did);
		}
		this->m_emparray[index] = work;
		index++;
	}
	//关闭文件
	ifs.close();
}
//显示职工
void WorkerManager::show_emp() {
	//判断文件是够为空
	if (this->m_fileisempty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			//利用多态调用程序接口
			this->m_emparray[i]->showinfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//删除职工
void WorkerManager::del_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或数据为空" << endl;
	}
	else {
		//按照职工编号进行排序
		cout << "请输入想要删除的职工号：" << endl;
		int id=0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {//说明该职工存在，并且要删除掉index位置上的职工
			for (int i = index; i < this->m_empnum - 1; i++) {
				//数据前移
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;//更新数组中记录的人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "查无此人，该职工不存在" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//判断职工是否存在，如果存在返回职工所在数组的位置，不存在返回-1
int WorkerManager::isexist(int id) {
	int index = -1;
	for (int i=0; i <this-> m_empnum; i++) {
		if (this->m_emparray[i]->m_Id ==id) {
			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void WorkerManager::mod_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或文件数据为空" << endl;
	}
	else {
		cout << "请输入职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1) {
			//找到此人
			delete this->m_emparray[ret];
			int  newid=0;
			string newname = "";
			int newdselect = 0;
			cout << "查找到" << id << "号员工,请输入新职工号：" << endl;
			cin>>newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入新的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newdselect;
			work* work = NULL;
			switch (newdselect)
			{
			case 1:
				work = new employee(newid, newname, newdselect);
				break;
			case 2:
				work = new manager(newid, newname, newdselect);
				break;
			case 3:
				work = new boss(newid, newname, newdselect);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_emparray[ret] = work;
			cout << "修改成功" << endl;
			//将数据保存到文件中
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::find_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或文件数据为空" << endl;
	}
	else {
		cout << "请输入查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//按照编号查找
			cout << "请输入职工编号" << endl;
			int id;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1) {
				//找到职工
				cout << "找到职工,该职工信息如下：" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2) {
			//按照姓名查按照
			string name;
			cout << "请输入职工姓名：" << endl;
			cin >> name;
			//加入职工是否找到的标志
			bool flag=false;//默认为未找到员工
			for(int i=0;i<this->m_empnum;i++)
				if (this->m_emparray[i]->m_name == name) {
					cout << "找到职工,该职工信息如下：" << endl;
					flag = true;
					this->m_emparray[i]->showinfo();
				}
			if (flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else {
			cout << "输入错误，请重新输入：" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//按照职工编号进行排序
void WorkerManager::sort_emp() {
	if (this->m_fileisempty) {
		cout << "文件不存在或文件数据为空" << endl;
		this->save();
		this->show_emp();
	}
	else {
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++)
		{
			int minOrMax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < m_empnum; j++)
			{
				if (select == 1) //升序
				{
					if (m_emparray[minOrMax]->m_Id > m_emparray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_emparray[minOrMax]->m_Id < m_emparray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//判断一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据
			if (i != minOrMax)
			{
				work* temp = m_emparray[i];
				m_emparray[i] = m_emparray[minOrMax];
				m_emparray[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->show_emp();
	}
}
//清空文件
void WorkerManager::clean_file() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_emparray = NULL) {
			//删除堆区的每一个职工对象
			for (int i; i < this->m_empnum; i++) {
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			//删除堆区数组指针
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_fileisempty = true;
		}
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->m_emparray != NULL) {
		delete[] m_emparray;
	}
}
