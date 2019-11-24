#pragma once
#ifndef _SOLUTIONS
#define _SOLUTIONS
#include<vector>
using namespace std;
class Solutions
{
public:
	vector<int>two_sums(vector<int>vec, int target)
	{
		vector<int>element;
		vector<int>::iterator it;
		int index = 0;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if (*it <= target)
			{
				element.push_back(index);
				target -= *it;
			}
			index++;
		}
		return element;
	}
};
#endif