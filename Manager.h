#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;

// ����������
class Manager : public Worker
{
public:
	Manager(int IDnumber, string name);

	void showInfo();
};