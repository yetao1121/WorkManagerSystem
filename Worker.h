#pragma once
#include <string>
#include <iostream>
using namespace std;

// ��������ְ����
class Worker
{
public:
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	int m_IDnumber;
	string m_Name;
	string m_Post;
	string m_Duty;
};