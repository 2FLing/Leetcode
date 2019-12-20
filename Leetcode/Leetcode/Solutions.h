#pragma once
#ifndef _SOLUTIONS
#define _SOLUTIONS
#include<vector>
#include<iostream>
#include<limits.h>
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
	//This function receive a 32 bit integer
	// and reverse the integer
	int reverse(int x)
	{
		if (x > INT32_MAX or x < INT32_MIN)
			return 0;
		else
		{
			int y = 0;
			while (x!=0)
			{
				y = y * 10 + x % 10;
				x /= 10;
			}
			return y;
		}
	}
};
#endif