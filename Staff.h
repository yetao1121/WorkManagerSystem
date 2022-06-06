#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// 创建普通员工类
class Staff : public Worker
{
public:
	Staff(int IDnumber, string name);

	void showInfo();
};