#include "voisk.h"
Voisk::Voisk(int n)
{
	time_t("NULL");
	
	for (int i = 0; i < n; i++)
	{
		soldier temp;
		temp.h = rand() % 50 + 150;
		vec.push_back(temp);
	}
}

void Voisk::sort(bool por)
{
	m.lock();
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
	m.unlock();
}

void Voisk::print()
{
	m.lock();
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1<< ". "<< vec[i].h << endl;
	}
	m.unlock();
}