#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// �����ϰ���
class Boss : public Worker
{
public:
	Boss(int IDnumber,string name);

	void showInfo();
};