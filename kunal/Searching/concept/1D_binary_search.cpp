#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int target)
{
	int start = 0;
	int end = arr.size() - 1;

	while(start<=end)
	{

		int mid = start + (end - start)/2; // note this line

		if(arr[mid] > target)
			end = mid - 1;
		else if (arr[mid] < target)
			start = mid + 1;
		else
			return mid;
	}

	return -1;
}

int order_agnostic_binary_search(vector<int> arr, int target)
{
	int start = 0;
	int end = arr.size() - 1;

	bool isAsc = arr[start] < arr[end];

	while(start <= end)
	{
		int mid = start + (end - start) / 2;

		if(arr[mid] == target)
			return mid;

		if (isAsc)
		{
			if(arr[mid] > target)
				end = mid - 1;
			else if (arr[mid] < target)
				start = mid + 1;
		}

		else
		{
			if(arr[mid] > target)
				start = mid + 1;
			else if (arr[mid] < target)
				end = mid - 1;
		}
	}

	return -1;
}

int main()
{
	vector<int> arr = {1,2,3,4,5,6};
	int target = 5;
	cout<<binary_search(arr, target)<<endl;

	// don't if vector is ascending or descending sorted
	reverse(arr.begin(), arr.end());
	cout<<order_agnostic_binary_search(arr, target)<<endl;
}