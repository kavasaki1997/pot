#include "voisk.h"
Voisk::Voisk(int n, int sizeGun)
{
	time_t("NULL");
	
	for (int i = 0; i < n; i++)
	{
		soldier temp;
		temp.h = rand() % 50 + 150;
		temp.power = rand() % 10  + 1;
		vec.push_back(temp);
	}
	for (int i = 0; i < sizeGun; i++)
	{
		gun temp;
		temp.mass = rand() % 50 + 150;
		guns.push_back(temp);
	}
}

void Voisk::sort(bool por)
{
	std::lock_guard<std::mutex> lock(m);
	for (int i = 0; i < vec.size() - 1; i++)
	{
		for (int j = 0; j < vec.size() - 1 - i; j++)
		{
			if (por)
			{
				if (vec[j].h > vec[j + 1].h)
				{
					swap(vec[j], vec[j + 1]);
				}
			}
			else
			{
				if (vec[j].h < vec[j + 1].h)
				{
					swap(vec[j], vec[j + 1]);
				}
			}
			
		}
	}


}

void Voisk::sortGuns(bool por)
{
	std::lock_guard<std::mutex> lock(m);
	for (int i = 0; i < guns.size() - 1; i++)
	{
		for (int j = 0; j < guns.size() - 1 - i; j++)
		{
			if (por)
			{
				if (guns[j].mass > guns[j + 1].mass)
				{
					swap(guns[j], guns[j + 1]);
				}
			}
			else
			{
				if (guns[j].mass < guns[j + 1].mass)
				{
					swap(guns[j], guns[j + 1]);
				}
			}

		}
	}
}

void Voisk::print()
{
	std::lock_guard<std::mutex> lock(m);
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1<< ". "<< vec[i].h << endl;
	}

}

void Voisk::fight(Voisk& v)
{

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].power < v.vec[i].power)
		{
			vec[i].health -= abs(vec[i].power - v.vec[i].power);
		}
		if (vec[i].health <= 0)
		{
			vec.erase(vec.begin() + i);
		}
	}
}

std::unique_lock<std::mutex> Voisk::getLock()
{
	std::unique_lock<std::mutex> lock(m);
	return lock; // Вызывается перемещающий конструктор unique_lock
}

