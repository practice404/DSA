#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v)
{
	size_t n = v.size();

	for(size_t i = 0; i < n - 1; ++i)
	{
		for(size_t j = i+1; j > 0; --j)
		{
			if(v[j] < v[j-1])
				swap(v[j], v[j-1]);
			else
				break;
		}
	}
}

int main()
{
	vector<int> v {4,9,-1,98,12,33,56,0};
	insertion_sort(v);

	for(auto i : v)
		cout<<i<<" ";
}