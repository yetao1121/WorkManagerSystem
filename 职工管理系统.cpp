#include <iostream>
#include <string>
#include <fstream>
#include "workerManager.h"
using namespace std;

//����ϵͳ����
//
//ְ������ϵͳ������������˾������Ա������Ϣ
//
//���̳���Ҫ���� C++ ��ʵ��һ�����ڶ�̬��ְ������ϵͳ
//
//��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ�Լ�ְ��
//
//��ͨԱ��ְ����ɾ����ɷ�������
//����ְ������ϰ��ɷ������񣬲��·������Ա��
//�ϰ�ְ�𣺹���˾��������
//
//����ϵͳ����Ҫʵ�ֵĹ������£�
//1���˳�����ϵͳ���˳���ǰ����ϵͳ
//2������ְ����Ϣ��ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ��ְ����š����������ű��
//3����ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
//4��ɾ����ְְ�������ձ��ɾ��ָ����ְ��
//5���޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
//6������ְ����Ϣ������ְ���ı�Ż���ְ�����������в��������Ա��Ϣ
//7�����ձ�����򣺰���ְ����ţ�������������������û�ָ��
//8����������ĵ�������ļ��м�¼������ְ����Ϣ�����ǰҪ�ٴ�ȷ�ϣ���ֹ��ɾ ��


int main()
{
	workerManager WM;
	int select;
	int index;
	while (true)
	{
		WM.showMenu();
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 0: // �˳�ϵͳ
			WM.existSystem();
			break;
		case 1: // ���ְ��
			WM.AddWorkers();
			break;
		case 2: // ��ʾְ��
			WM.showInfo();
			break;
		case 3: // ɾ��ְ��
			WM.deleteWorker();
			break;
		case 4: // �޸�ְ��
			WM.modifyWorker();
			break;
		case 5: // ����ְ��
			WM.searchWorker();
			break;
		case 6: // �������
			WM.sortWorker();
			break;
		case 7: // ����ĵ�
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