#include "Staff.h"

Staff::Staff(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "普通员工";
	m_Duty = "完成经理派发的任务";
}

void Staff::showInfo()
{
	cout << "职工编号：" << this->m_IDnumber << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：" << this->m_Post << "\t";
	cout << "岗位职责：" << this->m_Duty << endl;
}