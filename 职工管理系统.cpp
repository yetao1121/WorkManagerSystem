#include <iostream>
#include <string>
#include <fstream>
#include "workerManager.h"
using namespace std;

//管理系统需求
//
//职工管理系统可以用来管理公司内所有员工的信息
//
//本教程主要利用 C++ 来实现一个基于多态的职工管理系统
//
//公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位以及职责
//
//普通员工职责：完成经理派发的任务
//经理职责：完成老板派发的任务，并下发任务给员工
//老板职责：管理公司所有事物
//
//管理系统中需要实现的功能如下：
//1、退出管理系统：退出当前管理系统
//2、增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号
//3、显示职工信息：显示公司内部所有职工的信息
//4、删除离职职工：按照编号删除指定的职工
//5、修改职工信息：按照编号修改职工个人信息
//6、查找职工信息：按照职工的编号或者职工的姓名进行查找相关人员信息
//7、按照编号排序：按照职工编号，进行排序，排序规则由用户指定
//8、清空所有文档：清空文件中记录的所有职工信息（清空前要再次确认，防止误删 ）


int main()
{
	workerManager WM;
	int select;
	int index;
	while (true)
	{
		WM.showMenu();
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 0: // 退出系统
			WM.existSystem();
			break;
		case 1: // 添加职工
			WM.AddWorkers();
			break;
		case 2: // 显示职工
			WM.showInfo();
			break;
		case 3: // 删除职工
			WM.deleteWorker();
			break;
		case 4: // 修改职工
			WM.modifyWorker();
			break;
		case 5: // 查找职工
			WM.searchWorker();
			break;
		case 6: // 编号排序
			WM.sortWorker();
			break;
		case 7: // 清空文档
			WM.delAllWorker();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}