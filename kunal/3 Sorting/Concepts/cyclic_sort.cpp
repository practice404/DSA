#include<bits/stdc++.h>
using namespace std;

// applicable when the array contains element from 1 to N
// O(N)

void cycle_sort(vector<int> &v)
{
	size_t n = v.size();

	for(size_t i = 0; i < n - 1; ++i)
	{
		while(v[i] != i+1) // since in sorted (index = value - 1)
		{
			swap(v[i], v[v[i]-1]);
		}
	}
}

int main()
{
	vector<int> v {3,5,2,1,4};
	cycle_sort(v);

	for(auto i : v)
		cout<<i<<" ";
}