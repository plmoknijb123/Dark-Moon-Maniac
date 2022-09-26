#include"workerManager.h"
WorkerManager::WorkerManager() {
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open()) {
		//cout << "�ļ�������"<<endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_empnum = 0;
		//��ʼ������ָ��
		this->m_emparray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_empnum = 0;
		//��ʼ������ָ��
		this->m_emparray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_empnum();
	//cout << "ְ��������Ϊ��" << num << endl;
	this->m_empnum = num;
	//���ٿռ�
	this->m_emparray = new work * [this->m_empnum];
	//���ļ��е����ݴ浽������
	this->init_emp();
	
}
//չʾ�˵�
void WorkerManager::show_menu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitsystem() {
	cout << "��ӭ�´���ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}
//���Ա��
void WorkerManager::add_emp() {
	cout << "���������Ա����������" << endl;
	int addnum = 0;//�����û����������
	cin >> addnum;
	if (addnum > 0) {
		//���
		//��������¿ռ��С
		//�¿ռ��С=ԭ����¼����+��������
		int newsize = this->m_empnum + addnum;
		//�����¿ռ�
		work **newspace=new work*[newsize];
		//��ԭ���ռ�����ݿ������¿ռ���
		if (this->m_emparray != NULL) {
			for (int i = 0; i < this->m_empnum; i++) {
				newspace[i] =this-> m_emparray[i];
			}
		}
		//�������������
		for (int i = 0; i < addnum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dselect;//����ѡ��
			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�뱣�浽������
			newspace[this->m_empnum + i] = work;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_emparray;
		//�����¿ռ��ָ��
		this->m_emparray = newspace;
		//�����µ�ְ������
		this->m_empnum = newsize;
		//����ְ����Ϊ�յı�־
		this->m_fileisempty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addnum << "��Ա��" << endl;
		//�����ļ�
		this->save();
		
		
	}
	else{
		cout << "��������" << endl;
	}
	//������������������ϼ�Ŀ¼
	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�������ʽ���ļ����൱��д�ļ�
	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparray[i]->m_Id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ������ļ�
	int id;
	string name;
	int did;
	int num = 0;
	if (ifs >> id && ifs >> name && ifs >> did) {
		//ͳ����������
		num++;
	}
	return num;
}
//��ʼ��Ա��
void WorkerManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ������ļ�
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		work* work = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (did == 1)  // 1��ͨԱ��
		{
			work = new employee(id, name, did);
		}
		else if (did == 2)  // 2����
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
	//�ر��ļ�
	ifs.close();
}
//��ʾְ��
void WorkerManager::show_emp() {
	//�ж��ļ��ǹ�Ϊ��
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_empnum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_emparray[i]->showinfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//ɾ��ְ��
void WorkerManager::del_emp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else {
		//����ְ����Ž�������
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id=0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) {//˵����ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
			for (int i = index; i < this->m_empnum - 1; i++) {
				//����ǰ��
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;//���������м�¼����Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "���޴��ˣ���ְ��������" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������λ�ã������ڷ���-1
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
//�޸�ְ��
void WorkerManager::mod_emp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��ļ�����Ϊ��" << endl;
	}
	else {
		cout << "������ְ�����" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1) {
			//�ҵ�����
			delete this->m_emparray[ret];
			int  newid=0;
			string newname = "";
			int newdselect = 0;
			cout << "���ҵ�" << id << "��Ա��,��������ְ���ţ�" << endl;
			cin>>newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "�������µĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//�������ݵ�������
			this->m_emparray[ret] = work;
			cout << "�޸ĳɹ�" << endl;
			//�����ݱ��浽�ļ���
			this->save();
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//����ְ��
void WorkerManager::find_emp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��ļ�����Ϊ��" << endl;
	}
	else {
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//���ձ�Ų���
			cout << "������ְ�����" << endl;
			int id;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1) {
				//�ҵ�ְ��
				cout << "�ҵ�ְ��,��ְ����Ϣ���£�" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) {
			//���������鰴��
			string name;
			cout << "������ְ��������" << endl;
			cin >> name;
			//����ְ���Ƿ��ҵ��ı�־
			bool flag=false;//Ĭ��Ϊδ�ҵ�Ա��
			for(int i=0;i<this->m_empnum;i++)
				if (this->m_emparray[i]->m_name == name) {
					cout << "�ҵ�ְ��,��ְ����Ϣ���£�" << endl;
					flag = true;
					this->m_emparray[i]->showinfo();
				}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "����������������룺" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//����ְ����Ž�������
void WorkerManager::sort_emp() {
	if (this->m_fileisempty) {
		cout << "�ļ������ڻ��ļ�����Ϊ��" << endl;
		this->save();
		this->show_emp();
	}
	else {
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�
			for (int j = i + 1; j < m_empnum; j++)
			{
				if (select == 1) //����
				{
					if (m_emparray[minOrMax]->m_Id > m_emparray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (m_emparray[minOrMax]->m_Id < m_emparray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǣ���������
			if (i != minOrMax)
			{
				work* temp = m_emparray[i];
				m_emparray[i] = m_emparray[minOrMax];
				m_emparray[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->show_emp();
	}
}
//����ļ�
void WorkerManager::clean_file() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();
		if (this->m_emparray = NULL) {
			//ɾ��������ÿһ��ְ������
			for (int i; i < this->m_empnum; i++) {
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			//ɾ����������ָ��
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_fileisempty = true;
		}
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->m_emparray != NULL) {
		delete[] m_emparray;
	}
}
