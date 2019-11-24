#pragma once
#ifndef _SOLUTIONS
#define _SOLUTIONS
#include<vector>
#include<iostream>
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
	int reverse(int x)
	{
		int one, two, three,result;
		one = x / 100;
		two = x / 10 % 10;
		three = x % 10;
		if (three != 0)
		{
			result = three * 100 + two * 10 + one;
		}
		else
			result = two * 10 + one;
		return result;
	}
};
#endif