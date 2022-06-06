#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// 创建经理类
class Manager : public Worker
{
public:
	Manager(int IDnumber, string name);

	void showInfo();
};