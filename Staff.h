#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// ������ͨԱ����
class Staff : public Worker
{
public:
	Staff(int IDnumber, string name);

	void showInfo();
};