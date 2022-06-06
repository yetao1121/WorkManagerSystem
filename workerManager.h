#pragma once // 防止头文件重复包含
#define FILENAME "WorkerManager.txt"
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Boss.h"
#include "Manager.h"
#include "Staff.h"
using namespace std;

class workerManager
{
public:
	// 构造函数
	workerManager();

	// 展示菜单
	void showMenu();

	// 退出系统
	void existSystem();

	// 添加职工
	void AddWorkers();

	// 保存到文件中
	void save();

	//获取文件中保存的职工数量
	int getWorkerNum();

	// 初始化职工
	void initWorker();

	// 显示职工
	void showInfo();

	// 判断职工是否存在
	int isExist();
		
	// 删除职工
	void deleteWorker();

	// 修改职工
	void modifyWorker();

	// 查找职工
	void searchWorker();

	// 编号排序
	void sortWorker();

	// 清空文档
	void delAllWorker();

	// 析构函数
	~workerManager();


	Worker ** m_wmArray; // 职工数组指针
	int m_size;  //记录职工人数
	bool m_FileIsEmpty;
};