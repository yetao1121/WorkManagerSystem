#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// 创建老板类
class Boss : public Worker
{
public:
	Boss(int IDnumber,string name);

	void showInfo();
};