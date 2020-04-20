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
	vector<gun> guns;
	mutable mutex m;
	mutable mutex m1;
public:
	Voisk(int n, int sizeGun);
	void sort(bool por);
	void sortGuns(bool por);
	void print();
	void fight(Voisk& v);
	std::unique_lock<std::mutex>  getLock();
};
