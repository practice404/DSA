#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &v)
{
	bool swapped = false;
	size_t n = v.size();
	for(size_t i = 0; i < n; ++i)
	{
		for(size_t j = 1; j < n - i; ++j)
		{
			if(v[j] < v[j-1])
			{
				swap(v[j], v[j-1]);
				swapped = true;
			}
		}

		if(!swapped)
			break;
	}
}

int main()
{
	vector<int> v {4,9,-1,98,12,33,56,0};
	bubblesort(v);

	for(auto i : v)
		cout<<i<<" ";
}