#include "Manager.h"

Manager::Manager(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "����";
	m_Duty = "����ϰ��ɷ������񣬲��·������Ա��";
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_IDnumber << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ��" << this->m_Post << "\t";
	cout << "��λְ��" << this->m_Duty << endl;
}