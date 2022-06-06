#pragma once // ��ֹͷ�ļ��ظ�����
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
	// ���캯��
	workerManager();

	// չʾ�˵�
	void showMenu();

	// �˳�ϵͳ
	void existSystem();

	// ���ְ��
	void AddWorkers();

	// ���浽�ļ���
	void save();

	//��ȡ�ļ��б����ְ������
	int getWorkerNum();

	// ��ʼ��ְ��
	void initWorker();

	// ��ʾְ��
	void showInfo();

	// �ж�ְ���Ƿ����
	int isExist();
		
	// ɾ��ְ��
	void deleteWorker();

	// �޸�ְ��
	void modifyWorker();

	// ����ְ��
	void searchWorker();

	// �������
	void sortWorker();

	// ����ĵ�
	void delAllWorker();

	// ��������
	~workerManager();


	Worker ** m_wmArray; // ְ������ָ��
	int m_size;  //��¼ְ������
	bool m_FileIsEmpty;
};