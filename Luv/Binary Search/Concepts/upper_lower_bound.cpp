#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v, int target)
{
	int lo = 0, hi = v.size()-1;

	while(hi - lo > 1)
	{
		int mid = lo + ((hi - lo)/2);

		if(v[mid] < target)
			lo = mid + 1;
		else
			hi = mid;
	}

	if(v[lo] >= target)
		return lo;
	else if(v[hi] >= target)
		return hi;
	else
		return -1;
}

int upper_bound(vector<int> &v, int target)
{
	int lo = 0, hi = v.size()-1;

	while(hi - lo > 1)
	{
		int mid = lo + (hi - lo)/2;

		if (v[mid] <= target)
			lo = mid + 1;
		else
			hi = mid;
	}


	if (v[lo] > target)
		return lo;
	else if(v[hi] > target)
		return hi;
	else
		return -1;
}

int main()
{
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	cout<<v[lower_bound(v,5)]<<endl;
	cout<<v[upper_bound(v,5)]<<endl;
}