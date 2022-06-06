#include "workerManager.h"
#include <string>

// 构造函数
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in | ios::binary);

	// 当文件不存在时进行初始化
	if (!ifs.is_open())
	{
		this->m_size = 0;
		this->m_FileIsEmpty = true;
		this->m_wmArray = NULL;
		ifs.close();
		return;
	}
	// 文件存在且数据为空时进行初始化
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
	// 文件存在且保存有职工数据
	int num = this->getWorkerNum();
	this->m_size = num;
	// 开辟新空间并存放已有的职工信息
	this->m_wmArray = new Worker*[this->m_size];
	this->initWorker();
	this->m_FileIsEmpty = false;
	return;
}

// 展示菜单
void workerManager::showMenu()
{
	cout << "****************************" << endl;
	cout << "*** 欢迎使用职工管理系统 ***" << endl;
	cout << "***** 0、退出管理系统 ******" << endl;
	cout << "***** 1、增加职工信息 ******" << endl;
	cout << "***** 2、显示职工信息 ******" << endl;
	cout << "***** 3、删除离职职工 ******" << endl;
	cout << "***** 4、修改职工信息 ******" << endl;
	cout << "***** 5、查找职工信息 ******" << endl;
	cout << "***** 6、按照编号排序 ******" << endl;
	cout << "***** 7、清空所有文档 ******" << endl;
	cout << "****************************" << endl;
}

// 退出系统
void workerManager::existSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

// 添加职工
void workerManager::AddWorkers()
{
	cout << "请输入增加员工数量：";
	int num_add = 0;
	cin >> num_add;
	if (num_add > 0)
	{
		// 计算新空间大小
		int newSize = this->m_size + num_add;
		// 开辟新空间
		Worker** newspace = new Worker* [newSize];
		// 将原空间下内容存放到新空间下
		if(this->m_size != 0)
			for (int i = 0; i < this->m_size; i++)
			{
				newspace[i] = this->m_wmArray[i];
			}
		// 输入新数据
		for (int i = 0; i < num_add; i++)
		{
			int IDnumber;
			string name;
			int post_choice;
			cout << "请输入第 " << i + 1 << " 个新员工的职工编号：";
			cin >> IDnumber;
			cout << "请输入该员工的姓名：";
			cin >> name;
			cout << "请输入该员工的岗位（1、老板；2、经理；3、普通员工。）：";
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
			// 将创建的职工指针保存到指针数组中
			newspace[this->m_size + i] = wk;
		}
		// 释放原有空间
		delete[] this->m_wmArray;
		// 更新新空间指向
		this->m_wmArray = newspace;
		// 更新新的个数
		this->m_size = newSize;
		// 保存到文件中
		this->save();
		// 更新文件不为空标志
		this->m_FileIsEmpty = false;
		// 提示信息
		cout << "成功添加 " << num_add << " 名新职工！" << endl;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

// 保存到文件中
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

// 获取文件中保存的职工数量
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

// 初始化员工
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
		if (post == "普通员工")
		{
			worker = new Staff(id, name);
		}
		else if (post == "经理")
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

// 显示职工
void workerManager::showInfo()
{
	if (this->m_size == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			// 利用多态调用程序接口
			this->m_wmArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

// 判断职工是否存在并返回在数组中的位置
int workerManager::isExist()
{
	cout << "请输入查找职工信息方式（1、按职工编号查找；2、按姓名查找。）：";
	int sermethod_choice;
	cin >> sermethod_choice;
	int index = -1;
	if (sermethod_choice == 1)
	{
		cout << "请输入职工编号：";
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
		cout << "请输入职工姓名：";
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

// 删除职工
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
		cout << "已成功删除该离职职工信息！" << endl;
	}
	else
	{
		cout << "在职职工中没有此职工！" << endl;
	}	
	system("pause");
	system("cls");
}

// 修改职工
void workerManager::modifyWorker()
{
	int modify_index;
	modify_index = this->isExist();
	if (modify_index >= 0)
	{
		cout << "该职工的原信息为：" << endl;
		this->m_wmArray[modify_index]->showInfo();
		delete this->m_wmArray[modify_index];

		int IDnumber;
		string name;
		int post_choice;
		cout << "请输入该职工修改后的信息：" << endl;
		cout << "职工编号：";
		cin >> IDnumber;
		cout << "姓名：";
		cin >> name;
		cout << "岗位（1、老板；2、经理；3、普通员工。）：";
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
			cout << "输入有误！" << endl;
			break;
		}
		m_wmArray[modify_index] = wk;
		this->save();
		cout << "已成功修改该职工信息！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "在职职工中没有此职工！" << endl;
		system("pause");
		system("cls");
	}
}

// 查找职工
void workerManager::searchWorker()
{
	int ser_index;
	ser_index = this->isExist();
	if (ser_index >= 0)
	{
		cout << "该职工的信息为：" << endl;
		this->m_wmArray[ser_index]->showInfo();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "在职职工中没有此职工！" << endl;
		system("pause");
		system("cls");
	}
}

// 编号排序
void workerManager::sortWorker()
{
	int sortMethod_choice;
	cout << "请输入排序方式（1、按职工编号升序排序；2、按职工编号降序排序。）：";
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
		cout << "已成功将职工按照编号升序排列。" << endl;
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
		cout << "已成功将职工按照编号升序排列。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
	}
}

// 清空文档
void workerManager::delAllWorker()
{
	cout << "请问您确认要清空文档吗？(1、确认；2、取消。)";
	int del_choice;
	cin >> del_choice;
	switch (del_choice)
	{
	case 1:
	{
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc); // 删除文件后再重新创建
		ofs.close();
		// 是否堆区数据
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
		cout << "已成功清空文档！" << endl;
		break;
	}
	case 2:
		cout << "已取消！" << endl;
		break;
	default:
		cout << "输入有误！" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//析构函数
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