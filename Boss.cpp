#include "Boss.h"

Boss::Boss(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "�ϰ�";
	m_Duty = "����˾��������";
}
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_IDnumber << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ��" << this->m_Post << "\t";
	cout << "��λְ��" << this->m_Duty << endl;
}