#include "Staff.h"

Staff::Staff(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "��ͨԱ��";
	m_Duty = "��ɾ����ɷ�������";
}

void Staff::showInfo()
{
	cout << "ְ����ţ�" << this->m_IDnumber << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ��" << this->m_Post << "\t";
	cout << "��λְ��" << this->m_Duty << endl;
}