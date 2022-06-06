#include "Manager.h"

Manager::Manager(int IDnumber, string name)
{
	m_IDnumber = IDnumber;
	m_Name = name;
	m_Post = "经理";
	m_Duty = "完成老板派发的任务，并下发任务给员工";
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_IDnumber << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：" << this->m_Post << "\t";
	cout << "岗位职责：" << this->m_Duty << endl;
}