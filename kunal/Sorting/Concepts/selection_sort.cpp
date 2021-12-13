#include<bits/stdc++.h>
using namespace std;

int get_max_element_index(vector<int> &v, int start, int end)
{
	int max_index = 0;
	int max_ = INT_MIN;
	for(int i = start; i <= end; ++i)
	{
		if(v[i] > max_)
		{
			max_ = v[i];
			max_index = i;
		}
	}

	return max_index;
}
int get_min_element_index(vector<int> &v, int start, int end)
{
	int max_index = 0;
	int max_ = INT_MAX;
	for(int i = start; i <= end; ++i)
	{
		if(v[i] < max_)
		{
			max_ = v[i];
			max_index = i;
		}
	}

	return max_index;
}

void selection_sort(vector<int> &v, bool largest)
{
	size_t n = v.size();

	for(size_t i = 0; i < n; ++i)
	{
		if(largest)
		{
			int largest_index = n - i - 1;

			int max_element = get_max_element_index(v, 0, largest_index);

			swap(v[largest_index], v[max_element]);
		}

		else
		{
			int min_index = i;
			int min_element = get_min_element_index(v, min_index, n-1);
			swap(v[min_element], v[min_index]);
		}
		
	}
}

int main()
{
	vector<int> v {4,9,-1,98,12,33,56,0};
	selection_sort(v, true);

	for(auto i : v)
		cout<<i<<" ";
}