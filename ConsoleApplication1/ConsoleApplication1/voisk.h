#pragma once

#include <iostream>
#include "structs.h"
#include <vector>
#include <mutex>
using namespace std;
class Voisk
{
private:
	vector<soldier> vec;
	mutable mutex m;
public:
	Voisk(int n);
	void sort(bool por);
	void print();
};
