#include "Boss.h"

Boss::Boss(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "老板";
	m_Duty = "管理公司所有事物";
}
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_IDnumber << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：" << this->m_Post << "\t";
	cout << "岗位职责：" << this->m_Duty << endl;
}