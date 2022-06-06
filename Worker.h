#pragma once
#include <string>
#include <iostream>
using namespace std;

// 创建抽象职工类
class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;
	int m_IDnumber;
	string m_Name;
	string m_Post;
	string m_Duty;
};