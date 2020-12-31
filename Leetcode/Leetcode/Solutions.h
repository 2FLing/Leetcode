#pragma once
#ifndef _SOLUTIONS
#define _SOLUTIONS
#include<vector>
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<string>
#include<map>
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
			while (x != 0)
			{
				y = y * 10 + x % 10;
				x /= 10;
			}
			return y;
		}
	}
	//find the median of two sorted arrays
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
		{
			return findMedianSortedArrays(nums2, nums1);
		}
		int x = nums1.size();
		int y = nums2.size();
		int low = 0;
		int high = x;
		while (low <= high)
		{
			int partitionX = (low + high) / 2;
			int partitionY = (x + y + 1) / 2 - partitionX;
			int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
			int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
			int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
			int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

			if (maxLeftX <= minRightY and maxLeftY <= minRightX)
			{
				if ((x + y) % 2 == 0)
					return (double(max(maxLeftX, maxLeftY)) + double(min(minRightX, minRightY))) / 2;
				else
					return double(max(maxLeftX, maxLeftY));
			}
			else if (maxLeftX > minRightY)
			{
				high = partitionX - 1;
			}
			else
				low = partitionX + 1;
		}
		return 0;

	}
	/*Given an array of n positive integersand a positive integer s,
	find the minimal length of a contiguous subarray of which the sum ≥ s.If there isn't one, return 0 instead.
	Input: s = 7, nums = [2, 3, 1, 2, 4, 3]
	Output : 2
	Explanation : the subarray[4, 3] has the minimal length under the problem constraint.*/
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int n = nums.size();
		int ans = INT_MAX;
		int left = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			while (sum >= s)
			{
				ans = min(ans, i + 1 - left);
				sum -= nums[left++];
			}
		}
		return (ans == INT_MAX ? 0 : ans);
	}
	/*Given an array numsand a value val, remove all instances of that value in - place and return the new length.*/
	/*Input: nums = [3, 2, 2, 3], val = 3
	Output : 2, nums = [2, 2]
	Explanation : Your function should return length = 2, with the first two elements of nums being 2.
	It doesn't matter what you leave beyond the returned length.
	For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.*/
	int removeElement(vector<int>& nums, int val)
	{
		int n = nums.size();
		int i = 0;
		while (i < n)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[n - 1];
				n--;
			}
			else
				i++;
		}
		return n;
	}
	/*Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".*/
	/*Input: strs = ["flower", "flow", "flight"]
	Output : "fl"
	Input : strs = ["dog", "racecar", "car"]
	Output : ""
	Explanation : There is no common prefix among the input strings.*/
	string get_common(string str1, string str2)
	{
		int n = min(str1.length(), str2.length());
		string common = "";
		for (int i = 0; i < n; i++)
		{
			if (str1.at(i) == str2.at(i))
				common.push_back(str1.at(i));
			else
				break;
		}
		return common;
	}
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0)
			return "";
		string common = strs[0];
		for (auto ele : strs)
		{
			common = get_common(ele, common);
		}
		return common;
	}
	/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	Input: s = "()"
	Output : true
	Input : s = "(]"
	Output : false*/
	bool isValid(string s)
	{
		if (s == "")
			return false;
		vector<char>vec;
		pair<char, char>p1('(', ')');
		pair<char, char>p2('[', ']');
		pair<char, char>p3('{', '}');
		for (auto ele : s)
		{
			if (ele == '(' or ele == '[' or ele == '{')
				vec.push_back(ele);
			else if (ele == ')' or ele == ']' or ele == '}')
			{
				if (vec.empty())
					return false;
				else if (ele == p1.second and vec[vec.size() - 1] == p1.first)
					vec.pop_back();
				else if (ele == p2.second and vec[vec.size() - 1] == p2.first)
					vec.pop_back();
				else if (ele == p3.second and vec[vec.size() - 1] == p3.first)
					vec.pop_back();
				else
					return false;
			}
		}
		return vec.empty();

	}
	/*Given a non - empty array of decimal digits representing a non - negative integer, increment one to the integer.
	The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
	You may assume the integer does not contain any leading zero, except the number 0 itself.*/
	/*Input: digits = [1, 2, 3]
	Output : [1, 2, 4]
	Explanation : The array represents the integer 123.*/
	vector<int> plusOne(vector<int>& digits) {
		int mover = 0;
		digits[digits.size() - 1]++;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] == 10)
			{
				if (i == 0)
				{
					digits[i] = 1;
					for (int j = 1; j < digits.size(); j++)
						digits[j] = 0;
					digits.push_back(0);
				}
				else
				{
					digits[i] = 0;
					digits[i - 1]++;
				}
			}
		}
		return digits;
	}
	/*Pascal's triangle*/
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>vec;
		vector<int>preEle;
		vector<int>newEle;
		if (numRows != 0)
		{
			preEle.push_back(1);
			vec.push_back(preEle);
			for (int i = 1; i < numRows; i++)
			{
				preEle = vec[i - 1];
				newEle.clear();
				newEle.push_back(1);
				for (int j = 0; j < preEle.size() - 1; j++)
				{
					newEle.push_back(preEle[j] + preEle[j + 1]);
				}
				newEle.push_back(1);
				vec.push_back(newEle);
			}
		}
		return vec;
	}
	/*Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
	Notice that the row index starts from 0.*/
	vector<int> getRow(int rowIndex) {
		vector<vector<int>>vec;
		vector<int>preVec;
		vector<int>newVec;
		preVec.push_back(1);
		vec.push_back(preVec);
		for (int i = 1; i <= rowIndex; i++)
		{
			preVec = vec[i - 1];
			newVec.clear();
			newVec.push_back(1);
			for (int j = 0; j < preVec.size() - 1; j++)
			{
				newVec.push_back(preVec[j] + preVec[j + 1]);
			}
			newVec.push_back(1);
			vec.push_back(newVec);
		}
		return vec[rowIndex];
	}
	/*Given two sorted integer arrays nums1and nums2, merge nums2 into nums1 as one sorted array.
	Note:
	The number of elements initialized in nums1and nums2 are mand n respectively.
	You may assume that nums1 has enough space(size that is equal to m + n) to hold additional elements from nums2.
	Example :
	Input :
	nums1 = [1, 2, 3, 0, 0, 0], m = 3
	nums2 = [2, 5, 6], n = 3
	Output : [1, 2, 2, 3, 5, 6]*/
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0;
		while (i < nums1.size() and j < n)
		{
			if (nums1[i] < nums2[j])
			{
				if (i == m)
				{
					nums1[i++] = nums2[j++];
					m++;
				}
				else
					i++;
			}
			else
			{
				for (int k = nums1.size() - 2; k >= i; k--)
					nums1[k + 1] = nums1[k];
				nums1[i++] = nums2[j++];
				m++;
			}
		}


	}
	/*Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
	Note that you cannot sell a stock before you buy one.
	Example 1:

	Input: [7, 1, 5, 3, 6, 4]
	Output : 5
	Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
	Not 7 - 1 = 6, as selling price needs to be larger than buying price.

	Example 2 :
	Input : [7, 6, 4, 3, 1]
	Output : 0
	Explanation : In this case, no transaction is done, i.e.max profit = 0.*/
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = prices.size()-1; i >= 1; i--)
		{
			for (int j = i - 1; j >= 0; j--)
				profit = max(profit,prices[i] - prices[j]);
		}
		return profit;
	}
	/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
	Input: numbers = [2, 7, 11, 15], target = 9
	Output : [1, 2]
	Explanation : The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.*/
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = numbers.size() - 1;
		while (l < r)
		{
			if (numbers[l] + numbers[r] > target)
				r--;
			else if (numbers[l] + numbers[r] < target)
				l++;
			else
				return { l + 1,r + 1 };
		}
		return {};
	}
	/*Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
	You may assume that the array is non - empty and the majority element always exist in the array.*/
	//Input: [2, 2, 1, 1, 1, 2, 2]
	//Output : 2
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		return nums[nums.size() / 2];

	}
	/*Given an array of integers, find if the array contains any duplicates.
	Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.*/
	//Input: [1, 2, 3, 1]
	//Output : true
	//Input: [1, 2, 3, 4]
	//Output : false
	bool containsDuplicate(vector<int>& nums) {
		if (nums.empty())
			return false;
		else
		{
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size() - 1; i++)
			{
				if (nums[i] == nums[i + 1])
					return true;
			}
			return false;
		}

	}
};
#endif