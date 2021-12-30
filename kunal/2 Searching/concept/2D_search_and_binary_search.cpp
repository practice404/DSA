#include<bits/stdc++.h>
using namespace std;

// O(2N) => O(N)
// matirx is not strictly sorted
pair<int,int> matrix_search(vector<vector<int>> & v, int target)
{
	int row = v.size();
	int col = v[0].size();

	int r = 0;
	int c = col - 1;

	while(r < row && c >= 0)
	{
		if(v[r][c] == target)
			return {r,c};
		else if(v[r][c] < target)
			r++;
		else
			c--; 
	}

	return {-1,-1};
}

// O(log(m+n))
// matirx is strictly sorted
pair<int,int> matrix_binary_search(vector<vector<int>> & v, int target)
{
	int rstart = 0;
	int rend = v.size()-1;
	int cstart = 0;
	int cend = v[0].size()-1;

	while(rstart < rend)
	{
		int mid_col = (cstart+cend)/2;
		int mid_row = (rstart+rend)/2;

		if(v[mid_row][mid_col] == target)
			return {mid_row,mid_col};
		else if(v[mid_row][mid_col] < target)
			rstart = mid_row + 1;
		else
			rend = mid_row - 1;
	}

	while(cstart <= cend)
	{
		int mid = (cstart+cend)/2;
		if(v[rend][mid] == target)
			return {rend,mid};
		else if(v[rend][mid] < target)
			cstart = mid + 1;
		else
			cend = mid - 1;
	}

	return {-1,-1};
}

int main()
{
	// not strictly sorted matrix

	vector<vector<int>> v1 = {
		{10,20,30,40},
		{15,25,35,45},
		{28,29,37,49},
		{33,34,35,88}
	};

	auto ans1 = matrix_search(v1,33);
	cout<<ans1.first<<" , "<<ans1.second<<endl;

	// strictly sorted matrix
	vector<vector<int>> v2 = { 
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};	

	auto ans2 = matrix_binary_search(v2,8);
	cout<<ans2.first<<" , "<<ans2.second<<endl;


	
}