#include "workerManager.h"
#include <string>

// ���캯��
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in | ios::binary);

	// ���ļ�������ʱ���г�ʼ��
	if (!ifs.is_open())
	{
		this->m_size = 0;
		this->m_FileIsEmpty = true;
		this->m_wmArray = NULL;
		ifs.close();
		return;
	}
	// �ļ�����������Ϊ��ʱ���г�ʼ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_size = 0;
		this->m_FileIsEmpty = true;
		this->m_wmArray = NULL;
		ifs.close();
		return;
	}
	// �ļ������ұ�����ְ������
	int num = this->getWorkerNum();
	this->m_size = num;
	// �����¿ռ䲢������е�ְ����Ϣ
	this->m_wmArray = new Worker*[this->m_size];
	this->initWorker();
	this->m_FileIsEmpty = false;
	return;
}

// չʾ�˵�
void workerManager::showMenu()
{
	cout << "****************************" << endl;
	cout << "*** ��ӭʹ��ְ������ϵͳ ***" << endl;
	cout << "***** 0���˳�����ϵͳ ******" << endl;
	cout << "***** 1������ְ����Ϣ ******" << endl;
	cout << "***** 2����ʾְ����Ϣ ******" << endl;
	cout << "***** 3��ɾ����ְְ�� ******" << endl;
	cout << "***** 4���޸�ְ����Ϣ ******" << endl;
	cout << "***** 5������ְ����Ϣ ******" << endl;
	cout << "***** 6�����ձ������ ******" << endl;
	cout << "***** 7����������ĵ� ******" << endl;
	cout << "****************************" << endl;
}

// �˳�ϵͳ
void workerManager::existSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

// ���ְ��
void workerManager::AddWorkers()
{
	cout << "����������Ա��������";
	int num_add = 0;
	cin >> num_add;
	if (num_add > 0)
	{
		// �����¿ռ��С
		int newSize = this->m_size + num_add;
		// �����¿ռ�
		Worker** newspace = new Worker* [newSize];
		// ��ԭ�ռ������ݴ�ŵ��¿ռ���
		if(this->m_size != 0)
			for (int i = 0; i < this->m_size; i++)
			{
				newspace[i] = this->m_wmArray[i];
			}
		// ����������
		for (int i = 0; i < num_add; i++)
		{
			int IDnumber;
			string name;
			int post_choice;
			cout << "������� " << i + 1 << " ����Ա����ְ����ţ�";
			cin >> IDnumber;
			cout << "�������Ա����������";
			cin >> name;
			cout << "�������Ա���ĸ�λ��1���ϰ壻2������3����ͨԱ��������";
			cin >> post_choice;
			Worker * wk = NULL;
			switch (post_choice)
			{
			case 1:
				wk = new Boss(IDnumber, name);
				break;
			case 2:
				wk = new Manager(IDnumber, name);
				break;
			case 3:
				wk = new Staff(IDnumber, name);
				break;
			default:
				break;
			}
			// ��������ְ��ָ�뱣�浽ָ��������
			newspace[this->m_size + i] = wk;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->m_wmArray;
		// �����¿ռ�ָ��
		this->m_wmArray = newspace;
		// �����µĸ���
		this->m_size = newSize;
		// ���浽�ļ���
		this->save();
		// �����ļ���Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		// ��ʾ��Ϣ
		cout << "�ɹ���� " << num_add << " ����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

// ���浽�ļ���
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::binary);

	for (int i = 0; i < this->m_size; i++)
	{
		ofs << this->m_wmArray[i]->m_IDnumber << "\t"
		 << this->m_wmArray[i]->m_Name << "\t"
		 << this->m_wmArray[i]->m_Post << "\t"
		 << this->m_wmArray[i]->m_Duty << endl;
	}
	ofs.close();
}

// ��ȡ�ļ��б����ְ������
int workerManager::getWorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id = 0;
	string name;
	string post;
	string duty;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> post && ifs >> duty)
	{
		num++;
	}
	ifs.close();
	return num;
}

// ��ʼ��Ա��
void workerManager::initWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id = 0;
	string name;
	string post;
	string duty;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> post && ifs >> duty)
	{
		Worker * worker = NULL;
		if (post == "��ͨԱ��")
		{
			worker = new Staff(id, name);
		}
		else if (post == "����")
		{
			worker = new Manager(id, name);
		}
		else
		{
			worker = new Boss(id, name);
		}
		this->m_wmArray[index] = worker;
		index++;
	}
	ifs.close();
}

// ��ʾְ��
void workerManager::showInfo()
{
	if (this->m_size == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			// ���ö�̬���ó���ӿ�
			this->m_wmArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ���ڲ������������е�λ��
int workerManager::isExist()
{
	cout << "���������ְ����Ϣ��ʽ��1����ְ����Ų��ң�2�����������ҡ�����";
	int sermethod_choice;
	cin >> sermethod_choice;
	int index = -1;
	if (sermethod_choice == 1)
	{
		cout << "������ְ����ţ�";
		int ser_idnumber;
		cin >> ser_idnumber;
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_wmArray[i]->m_IDnumber == ser_idnumber)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	else
	{
		cout << "������ְ��������";
		string ser_name;
		cin >> ser_name;
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_wmArray[i]->m_Name == ser_name)
			{
				index = i;
				break;
			}
		}
		return index;
	}
}

// ɾ��ְ��
void workerManager::deleteWorker()
{
	int del_index;
	del_index = this->isExist();
	if (del_index >= 0)
	{
		for (int i = del_index; i < this->m_size - 1; i++)
		{
			this->m_wmArray[i] = this->m_wmArray[i + 1];
		}
		this->m_size = this->m_size - 1;
		this->save();
		cout << "�ѳɹ�ɾ������ְְ����Ϣ��" << endl;
	}
	else
	{
		cout << "��ְְ����û�д�ְ����" << endl;
	}	
	system("pause");
	system("cls");
}

// �޸�ְ��
void workerManager::modifyWorker()
{
	int modify_index;
	modify_index = this->isExist();
	if (modify_index >= 0)
	{
		cout << "��ְ����ԭ��ϢΪ��" << endl;
		this->m_wmArray[modify_index]->showInfo();
		delete this->m_wmArray[modify_index];

		int IDnumber;
		string name;
		int post_choice;
		cout << "�������ְ���޸ĺ����Ϣ��" << endl;
		cout << "ְ����ţ�";
		cin >> IDnumber;
		cout << "������";
		cin >> name;
		cout << "��λ��1���ϰ壻2������3����ͨԱ��������";
		cin >> post_choice;
		Worker * wk = NULL;
		switch (post_choice)
		{
		case 1:
			wk = new Boss(IDnumber, name);
			break;
		case 2:
			wk = new Manager(IDnumber, name);
			break;
		case 3:
			wk = new Staff(IDnumber, name);
			break;
		default:
			cout << "��������" << endl;
			break;
		}
		m_wmArray[modify_index] = wk;
		this->save();
		cout << "�ѳɹ��޸ĸ�ְ����Ϣ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ְְ����û�д�ְ����" << endl;
		system("pause");
		system("cls");
	}
}

// ����ְ��
void workerManager::searchWorker()
{
	int ser_index;
	ser_index = this->isExist();
	if (ser_index >= 0)
	{
		cout << "��ְ������ϢΪ��" << endl;
		this->m_wmArray[ser_index]->showInfo();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ְְ����û�д�ְ����" << endl;
		system("pause");
		system("cls");
	}
}

// �������
void workerManager::sortWorker()
{
	int sortMethod_choice;
	cout << "����������ʽ��1����ְ�������������2����ְ����Ž������򡣣���";
	cin >> sortMethod_choice;
	if (sortMethod_choice == 1)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			for (int j = 0; j < this->m_size - i - 1; j++)
			{
				if (this->m_wmArray[j]->m_IDnumber > this->m_wmArray[j + 1]->m_IDnumber)
				{
					Worker *temp = this->m_wmArray[j];
					this->m_wmArray[j] = this->m_wmArray[j + 1];
					this->m_wmArray[j + 1] = temp;
				}
			}
		}
		this->save();
		cout << "�ѳɹ���ְ�����ձ���������С�" << endl;
		system("pause");
		system("cls");
	}
	else if (sortMethod_choice == 2)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			for (int j = 0; j < this->m_size - i - 1; j++)
			{
				if (this->m_wmArray[j]->m_IDnumber < this->m_wmArray[j + 1]->m_IDnumber)
				{
					Worker *temp = this->m_wmArray[j];
					this->m_wmArray[j] = this->m_wmArray[j + 1];
					this->m_wmArray[j + 1] = temp;
				}
			}
		}
		this->save();
		cout << "�ѳɹ���ְ�����ձ���������С�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}
}

// ����ĵ�
void workerManager::delAllWorker()
{
	cout << "������ȷ��Ҫ����ĵ���(1��ȷ�ϣ�2��ȡ����)";
	int del_choice;
	cin >> del_choice;
	switch (del_choice)
	{
	case 1:
	{
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc); // ɾ���ļ��������´���
		ofs.close();
		// �Ƿ��������
		if (this->m_wmArray != NULL)
		{
			for (int i = 0; i < this->m_size; i++)
			{
				if (this->m_wmArray[i] != NULL)
				{
					delete this->m_wmArray[i];
					this->m_wmArray[i] = NULL;
				}
			}
			delete[] this->m_wmArray;
			this->m_wmArray = NULL;
			this->m_size = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "�ѳɹ�����ĵ���" << endl;
		break;
	}
	case 2:
		cout << "��ȡ����" << endl;
		break;
	default:
		cout << "��������" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//��������
workerManager::~workerManager()
{
	if (this->m_wmArray != NULL)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_wmArray[i] != NULL)
			{
				delete this->m_wmArray[i];
			}
		}
	}
	delete[] this->m_wmArray;
}