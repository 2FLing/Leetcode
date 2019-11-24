#include"Solutions.h"
#include<iostream>
using namespace std;
int main()
{
	vector<int>vec1, vec2;
	vector<int>::iterator it;
	Solutions s1;
	int num;
	vec1.push_back(2);
	vec1.push_back(7);
	vec1.push_back(11);
	vec1.push_back(15);
	vec2 = s1.two_sums(vec1, 9);
	for (it = vec2.begin(); it != vec2.end(); it++)
		cout << *it << " ";
	cout << endl;
	num = s1.reverse(120);
	cout << num << endl;
	return 0;
}